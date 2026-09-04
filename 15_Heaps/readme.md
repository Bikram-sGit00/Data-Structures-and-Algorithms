# Heap on Pairs — Notes

## 1. Priority Queue basics (recap)

```cpp
#include <queue>

priority_queue<int> maxHeap;        // default: max-heap
priority_queue<int, vector<int>, greater<int>> minHeap; // min-heap

maxHeap.push(5);
maxHeap.top();     // largest element
maxHeap.pop();
maxHeap.empty();
maxHeap.size();
```

Default `priority_queue<T>` is a **max-heap**. To flip it to min-heap you pass
`greater<T>` as the third template argument. That third argument is the
comparator — everything below is just a bigger version of this idea.

---

## 2. Heap on pairs — plain syntax

```cpp
priority_queue<pair<int,int>> pq;   // default max-heap of pairs

pq.push({3, 10});
pq.push({7, 2});
pq.push({3, 99});
```

**Key rule: pairs compare lexicographically.**
First compare `.first`. If `.first` is equal, compare `.second`.

So for the pairs above, top() would be `{7,2}` (7 > 3, first element wins).
If two pairs tie on `.first`, the one with bigger `.second` wins in a
max-heap (since it's max-max by default).

Example:
```cpp
pq.push({3,10});
pq.push({3,99});
pq.top(); // {3,99}  -> first is tied at 3, second decides, 99 > 10
```

---

## 3. Comparator — how it actually works

A comparator answers one question: **"is A less than B?"**

`priority_queue` puts whatever the comparator says is "biggest" at the top.
- If `cmp(a,b)` returns true when a should come *before* b in "less-than"
  sense, the heap behaves as usual (max on top by default logic).
- Comparator returning `true` means "a has lower priority than b" (a should
  sit below b). This is the part people get confused by — think of it as
  `operator<`.

### Ways to write it

**A) Lambda (most common, modern C++):**
```cpp
auto cmp = [](pair<int,int>& a, pair<int,int>& b) {
    return a.first > b.first;   // explained below
};
priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
```
`decltype(cmp)` is needed because a lambda's type is unique/anonymous —
you can't just write "function" as the type, so you let the compiler
deduce it.

**B) Struct with operator() overload:**
```cpp
struct cmp {
    bool operator()(pair<int,int>& a, pair<int,int>& b) {
        return a.first > b.first;
    }
};
priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
```
No `decltype` needed here since `cmp` is already a named type.

Both do the exact same thing. Lambda is shorter, struct is easier to reuse
across multiple places in a large file.

---

## 4. The four variants: min-min, min-max, max-min, max-max

This is about **which field controls the ordering, and in which
direction**, when you're ordering pairs `{key, value}`.

### 4.1 max-max (default behavior, no comparator needed)
```cpp
priority_queue<pair<int,int>> pq;
```
Orders by `.first` descending, ties broken by `.second` descending.
Top = pair with largest first, and among ties, largest second.

### 4.2 min-min
```cpp
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
```
`greater<pair<int,int>>` flips both fields to ascending automatically
(it just reverses the whole lexicographic comparison).
Top = pair with smallest first, ties broken by smallest second.

### 4.3 max-min (first descending, second ascending — custom logic needed)
```cpp
auto cmp = [](pair<int,int>& a, pair<int,int>& b) {
    if (a.first != b.first) return a.first < b.first;  // bigger first on top
    return a.second > b.second;                          // smaller second on top
};
priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
```

### 4.4 min-max (first ascending, second descending)
```cpp
auto cmp = [](pair<int,int>& a, pair<int,int>& b) {
    if (a.first != b.first) return a.first > b.first;  // smaller first on top
    return a.second < b.second;                          // bigger second on top
};
priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
```

**Trick to remember direction:** in `return a.X < b.X`, if this expression
is true, it means a's X value makes a "less important" → a sinks, b rises
→ **smaller X ends up at the bottom, bigger X floats to top**. So
`a.X < b.X` gives you "bigger X on top" for that field. Flip the `<` to `>`
to get "smaller X on top" for that field. Apply this per-field for
whichever direction you want (max or min) on first and second
independently. That's literally all 4 combinations are.

---

## 5. Applying it to Top K Frequent Elements (brute force with heap on pairs)

**Problem:** given `nums` and `k`, return the `k` most frequent elements.

**Brute force idea:**
1. Count frequency of every number using `unordered_map<int,int>`.
2. Push `{frequency, number}` pairs into a **max-heap**.
3. Pop the top `k` times — each pop gives you the next most frequent
   element.

Why `{frequency, number}` and not `{number, frequency}`? Because heap
orders by `.first`, and we want to order by frequency, so frequency must
be `.first`.

```cpp
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    for (int n : nums) freq[n]++;              // count frequencies

    priority_queue<pair<int,int>> maxHeap;      // default max-heap, orders by .first
    for (auto& [num, count] : freq) {
        maxHeap.push({count, num});             // {frequency, number}
    }

    vector<int> result;
    while (k--) {
        result.push_back(maxHeap.top().second); // grab the number
        maxHeap.pop();
    }
    return result;
}
```

### Example walkthrough
`nums = [1,1,1,2,2,3]`, `k = 2`

Frequency map: `{1:3, 2:2, 3:1}`

Push into max-heap as `{freq, num}`:
`{3,1}, {2,2}, {1,3}`

Heap top is always the largest `.first`, so pop order:
1. `{3,1}` → push `1` to result
2. `{2,2}` → push `2` to result

`result = [1, 2]` ✅ matches expected output.

---

## 6. Space & Time Complexity (brute force)

- Building frequency map: `O(n)` time, `O(n)` space (n = size of nums)
- Pushing all unique elements into heap: `O(u log u)` time where `u` =
  number of unique elements (each push is `O(log u)`)
- Popping k times: `O(k log u)`
- **Total time:** `O(n + u log u)`, worst case `u = n` so `O(n log n)`
- **Total space:** `O(n)` for the map + heap

This is the brute force because we push **all** unique elements into the
heap, even though we only need the top `k`. The optimization (next step)
avoids that by keeping the heap size capped at `k`.





<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<title>Heap Problem Template</title>
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.9.0/styles/base16/tomorrow-night.min.css">
<script src="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.9.0/highlight.min.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.9.0/languages/cpp.min.js"></script>
<style>
  @import url('https://fonts.googleapis.com/css2?family=Space+Grotesk:wght@500;600;700&family=Inter:wght@400;500;600&family=IBM+Plex+Mono:wght@400;500&display=swap');

  :root{
    --bg: #14161c;
    --surface: #1b1e27;
    --surface-2: #20232e;
    --border: #2a2e3a;
    --text: #e8e6e1;
    --text-dim: #9298a8;
    --min-heap: #5fb3a3;   /* teal = min-heap / ascending */
    --max-heap: #d99a5f;   /* amber = max-heap / descending */
    --min-heap-bg: rgba(95,179,163,0.12);
    --max-heap-bg: rgba(217,154,95,0.12);
  }

  *{ box-sizing:border-box; }

  body{
    margin:0;
    background:var(--bg);
    color:var(--text);
    font-family:'Inter', sans-serif;
    line-height:1.65;
  }

  .page{
    max-width:760px;
    margin:0 auto;
    padding:64px 24px 96px;
  }

  h1,h2,h3{
    font-family:'Space Grotesk', sans-serif;
    color:var(--text);
    letter-spacing:-0.01em;
  }

  h1{
    font-size:2rem;
    margin:0 0 8px;
  }

  .subtitle{
    color:var(--text-dim);
    font-size:1.02rem;
    max-width:56ch;
    margin:0 0 56px;
  }

  section{
    margin-bottom:52px;
  }

  .step-head{
    display:flex;
    align-items:baseline;
    gap:14px;
    margin-bottom:14px;
  }

  .step-num{
    font-family:'IBM Plex Mono', monospace;
    font-size:0.85rem;
    color:var(--text-dim);
    border:1px solid var(--border);
    border-radius:6px;
    padding:2px 8px;
    flex-shrink:0;
  }

  h2{
    font-size:1.28rem;
    margin:0;
  }

  p{
    color:#c7c9d1;
    font-size:0.98rem;
  }

  /* decision table */
  table{
    width:100%;
    border-collapse:collapse;
    font-size:0.92rem;
    margin-top:18px;
  }

  th{
    text-align:left;
    font-family:'Space Grotesk', sans-serif;
    font-weight:600;
    font-size:0.82rem;
    color:var(--text-dim);
    padding:0 14px 10px 0;
    border-bottom:1px solid var(--border);
  }

  td{
    padding:14px 14px 14px 0;
    border-bottom:1px solid var(--border);
    vertical-align:top;
    color:#c7c9d1;
  }

  tr:last-child td{ border-bottom:none; }

  .badge{
    display:inline-block;
    font-family:'IBM Plex Mono', monospace;
    font-size:0.78rem;
    padding:3px 9px;
    border-radius:20px;
    white-space:nowrap;
  }
  .badge.min{ background:var(--min-heap-bg); color:var(--min-heap); }
  .badge.max{ background:var(--max-heap-bg); color:var(--max-heap); }
  .badge.both{ background:linear-gradient(90deg, var(--min-heap-bg), var(--max-heap-bg)); color:var(--text); }

  td code{
    font-family:'IBM Plex Mono', monospace;
    font-size:0.8rem;
    color:var(--text);
    background:var(--surface-2);
    padding:2px 6px;
    border-radius:4px;
    white-space:nowrap;
  }

  /* code cards for step 2 */
  .card-grid{
    display:grid;
    grid-template-columns:1fr 1fr;
    gap:14px;
    margin-top:18px;
  }

  .card{
    background:var(--surface);
    border:1px solid var(--border);
    border-radius:10px;
    overflow:hidden;
  }

  .card-label{
    font-family:'IBM Plex Mono', monospace;
    font-size:0.76rem;
    color:var(--text-dim);
    padding:10px 14px;
    border-bottom:1px solid var(--border);
  }

  .card pre{ margin:0; }

  /* code blocks */
  pre{
    background:var(--surface) !important;
    border:1px solid var(--border);
    border-radius:10px;
    padding:16px 18px;
    overflow-x:auto;
    margin-top:16px;
  }

  code{
    font-family:'IBM Plex Mono', monospace !important;
    font-size:0.84rem;
    line-height:1.6;
  }

  .code-block-title{
    font-family:'IBM Plex Mono', monospace;
    font-size:0.76rem;
    color:var(--text-dim);
    margin:16px 0 -6px;
  }

  /* edge case list */
  .checklist{
    list-style:none;
    padding:0;
    margin:16px 0 0;
    display:grid;
    gap:8px;
  }
  .checklist li{
    display:flex;
    gap:10px;
    color:#c7c9d1;
    font-size:0.94rem;
  }
  .checklist li::before{
    content:"";
    width:5px;
    height:5px;
    border-radius:50%;
    background:var(--text-dim);
    margin-top:9px;
    flex-shrink:0;
  }

  .callout{
    border-left:2px solid var(--max-heap);
    background:var(--surface);
    border-radius:0 10px 10px 0;
    padding:18px 22px;
    margin-top:8px;
  }
  .callout p{ margin:0; }

  hr{
    border:none;
    border-top:1px solid var(--border);
    margin:52px 0;
  }

  @media (max-width:600px){
    .card-grid{ grid-template-columns:1fr; }
    .page{ padding:40px 18px 72px; }
  }
</style>
</head>
<body>
<div class="page">

  <h1>Heap Problem Template</h1>
  <p class="subtitle">A working skeleton for heap-based DSA questions — Kth largest, top-K frequent, K closest points, merge K lists, running median.</p>

  <section>
    <div class="step-head"><span class="step-num">01</span><h2>Decide the heap type from the problem signal</h2></div>
    <p>Match the question to a pattern before writing anything. The heap type is rarely the "obvious" one, so lock in the declaration syntax immediately.</p>
    <table>
      <tr><th>Signal</th><th>Heap</th><th>Declaration</th></tr>
      <tr>
        <td>Kth <b>largest</b> element</td>
        <td><span class="badge min">min-heap, size K</span></td>
        <td><code>priority_queue&lt;int, vector&lt;int&gt;, greater&lt;int&gt;&gt; pq;</code></td>
      </tr>
      <tr>
        <td>Kth <b>smallest</b> element</td>
        <td><span class="badge max">max-heap, size K</span></td>
        <td><code>priority_queue&lt;int&gt; pq;</code></td>
      </tr>
      <tr>
        <td>Repeated max, no K limit</td>
        <td><span class="badge max">max-heap</span></td>
        <td><code>priority_queue&lt;int&gt; pq;</code></td>
      </tr>
      <tr>
        <td>Repeated min, no K limit</td>
        <td><span class="badge min">min-heap</span></td>
        <td><code>priority_queue&lt;int, vector&lt;int&gt;, greater&lt;int&gt;&gt; pq;</code></td>
      </tr>
      <tr>
        <td>K closest points (distance)</td>
        <td><span class="badge max">max-heap, size K</span></td>
        <td><code>priority_queue&lt;pair&lt;int,pair&lt;int,int&gt;&gt;&gt; pq;</code></td>
      </tr>
      <tr>
        <td>Top-K frequent elements</td>
        <td><span class="badge min">min-heap, size K</span></td>
        <td><code>priority_queue&lt;pair&lt;int,int&gt;,vector&lt;pair&lt;int,int&gt;&gt;,greater&lt;&gt;&gt; pq;</code></td>
      </tr>
      <tr>
        <td>Merge K sorted lists</td>
        <td><span class="badge min">min-heap</span></td>
        <td><code>priority_queue&lt;pair&lt;int,int&gt;,vector&lt;pair&lt;int,int&gt;&gt;,greater&lt;&gt;&gt; pq;</code></td>
      </tr>
      <tr>
        <td>Running median</td>
        <td><span class="badge both">max + min heap</span></td>
        <td><code>priority_queue&lt;int&gt; lo; priority_queue&lt;int,vector&lt;int&gt;,greater&lt;int&gt;&gt; hi;</code></td>
      </tr>
    </table>
  </section>

  <section>
    <div class="step-head"><span class="step-num">02</span><h2>Build the heap element</h2></div>
    <p>What you push depends on what you're comparing, not just what you're storing.</p>
    <div class="card-grid">
      <div class="card">
        <div class="card-label">distance-based</div>
        <pre><code class="language-cpp">int dist = x*x + y*y;
pair&lt;int,pair&lt;int,int&gt;&gt; elem = {dist, {x, y}};</code></pre>
      </div>
      <div class="card">
        <div class="card-label">frequency-based</div>
        <pre><code class="language-cpp">unordered_map&lt;int,int&gt; freq;
pair&lt;int,int&gt; elem = {freq[val], val};</code></pre>
      </div>
      <div class="card">
        <div class="card-label">index-tracking</div>
        <pre><code class="language-cpp">// pair&lt;value, listIndex&gt;
pair&lt;int,int&gt; elem = {lists[i][0], i};</code></pre>
      </div>
      <div class="card">
        <div class="card-label">custom struct</div>
        <pre><code class="language-cpp">struct Node {
    int val, row, col;
    bool operator&lt;(const Node& o) const {
        return val &gt; o.val; // min-heap behavior
    }
};</code></pre>
      </div>
    </div>
  </section>

  <section>
    <div class="step-head"><span class="step-num">03</span><h2>Initial push — heap not yet full</h2></div>
    <p>While the heap holds fewer than K elements, push unconditionally.</p>
    <pre><code class="language-cpp">if ((int)pq.size() &lt; k) {
    pq.push(elem);
}</code></pre>
  </section>

  <section>
    <div class="step-head"><span class="step-num">04</span><h2>Conditional push once heap is full</h2></div>
    <p>Every new element now competes with the current top — compare, then evict-and-push or skip.</p>
    <pre><code class="language-cpp">else if (elem.first &lt; pq.top().first) {  // flip the sign for max-heap logic
    pq.pop();       // evict the weakest candidate
    pq.push(elem);  // push the stronger one
}
// else: skip — current element doesn't beat what's already in the heap</code></pre>
  </section>

  <section>
    <div class="step-head"><span class="step-num">05</span><h2>Pop to build the answer</h2></div>
    <p>Drain the heap into the result. Order coming out is reversed from priority, so flip it if the problem wants ascending or descending output.</p>
    <pre><code class="language-cpp">vector&lt;int&gt; result;
while (!pq.empty()) {
    result.push_back(pq.top().second); // .second for pairs, top() for raw values
    pq.pop();
}
reverse(result.begin(), result.end()); // only if order matters</code></pre>
  </section>

  <section>
    <div class="step-head"><span class="step-num">06</span><h2>Edge cases & complexity</h2></div>
    <ul class="checklist">
      <li>Empty input, K = 0, or K larger than input size — handle before the loop starts</li>
      <li>Duplicate values or frequencies — decide if the problem needs stable tie-breaking</li>
      <li>Time: O(N log K) with a size-capped heap, O(N log N) for a full heap</li>
      <li>Space: O(K) or O(N), matching whichever of the above applies</li>
    </ul>
  </section>

  <hr>

  <section>
    <h2 style="margin-bottom:16px;">Full worked example — Kth largest</h2>
    <pre><code class="language-cpp">#include &lt;queue&gt;
#include &lt;vector&gt;
using namespace std;

int findKthLargest(vector&lt;int&gt;& nums, int k) {
    priority_queue&lt;int, vector&lt;int&gt;, greater&lt;int&gt;&gt; pq; // Step 1: min-heap for Kth largest

    for (int num : nums) {
        if ((int)pq.size() &lt; k) {
            pq.push(num);              // Step 3: heap not full yet, push directly
        } else if (num &gt; pq.top()) {
            pq.pop();                  // Step 4: evict smallest
            pq.push(num);              // push the stronger candidate
        }
    }

    return pq.top(); // Step 5: top of a size-K min-heap = Kth largest overall
    // Step 6: assumes k <= nums.size(), no dedup needed for this variant
}</code></pre>
  </section>

  <section>
    <div class="callout">
      <p><b>Interview framing:</b> state brute force first — sort descending and index <code style="background:var(--surface-2);padding:2px 6px;border-radius:4px;">[k-1]</code>, O(N log N) — then pivot to the heap approach and explain the O(N log K) win when K is much smaller than N.</p>
    </div>
  </section>

</div>
<script>hljs.highlightAll();</script>
</body>
</html>