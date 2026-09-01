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