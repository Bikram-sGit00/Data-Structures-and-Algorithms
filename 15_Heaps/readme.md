<div align="center">
  <h1>
    HEAP - Notes
  </h1>
</div>

## 1. What is a Heap?

A **heap** is a **complete binary tree** that follows the heap property.

There are two main types:

- **Max-Heap** → parent is always greater than or equal to its children.
- **Min-Heap** → parent is always smaller than or equal to its children.

> Important: A heap is **not a sorted tree**.
> It only guarantees that the **top/root element** has the required priority.

---

## 2. Complete Binary Tree

A heap must always be a **complete binary tree**.

That means:

1. Every level is completely filled except possibly the last level.
2. The last level is filled **from left to right**.

Example:

```
             50
           /    \
         30      40
        /  \    /
      10   20  35
```

This is a complete binary tree because the last level is filled from left to right.

---

## 3. Max-Heap

In a **Max-Heap**:

```
             50
           /    \
         30      40
        /  \    /
      10   20  35
```

Every parent is greater than its children:

```
50 > 30
50 > 40

30 > 10
30 > 20

40 > 35
```

So:

```
             50
           /    \
         30      40
        /  \    /
      10   20  35
```

The maximum element is always at the root:

```
             ↓
             50
```

---

# 4. Heap Representation Using an Array

Although we visualize a heap as a tree, we normally store it in an **array/vector**.

The above tree:

```
             50
           /    \
         30      40
        /  \    /
      10   20  35
```

is stored as:

```
Index:  0   1   2   3   4   5
        ↓   ↓   ↓   ↓   ↓   ↓
Array: [50, 30, 40, 10, 20, 35]
```

No pointers are required.

---

## 5. Parent and Child Index Formula

For an element at index `i`: (`0` based indexing)

```
Parent       = (i - 1) / 2

Left child   = 2 * i + 1

Right child  = 2 * i + 2
```

Example:

```
             50
           /    \
         30      40
        /  \    /
      10   20  35
```

Array:

```
[50, 30, 40, 10, 20, 35]
```

For `30`:

```
i = 1

Left child  = 2(1) + 1 = 3  → 10
Right child = 2(1) + 2 = 4  → 20
```

For `40`:

```
i = 2

Left child  = 2(2) + 1 = 5  → 35
```

# 6. Insertion in a Max-Heap

Suppose our current Max-Heap is:

```
             50
           /    \
         30      40
        /  \    /
      10   20  35
```

Array:

```
[50, 30, 40, 10, 20, 35]
```

Now insert:

```
45
```

### Step 1 — Insert at the next available position

Because a heap must remain a **complete binary tree**, we first put the new element at the next empty position.

```
             50
           /    \
         30      40
        /  \    / \
      10   20  35  45
```

Array:

```
[50, 30, 40, 10, 20, 35, 45]
```

But the heap property is broken:

```
40 < 45
```

So `45` must move upward.  Heapify

## 1. What is Heapify?

**Heapify** is the process of rearranging elements so that they follow the **heap property**.

For a **Max-Heap**:

```text
Parent >= Children

```

For a **Min-Heap**:

```text
Parent <= Children

```

Heapify does **not sort the entire array**.

It only fixes the heap property.

---

## 2. What Does Heapify Do?

Suppose we have:

```text
             20
           /    \
         50      30
        /  \
      10   40

```

Here `20 < 50`, so this is **not a Max-Heap**.

Heapify rearranges the tree:

```text
             50
           /    \
         40      30
        /  \
      10   20

```

Now every parent is greater than its children.

So this is a Max-Heap.

---

## 3. Heapify Down

Heapify commonly works by moving an element **downward** until the heap property is restored.

Example:

```text
             20
           /    \
         50      30

```

Compare `20` with its children:

```text
20, 50, 30

```

For Max-Heap, choose the **largest child = 50**.

Swap:

```text
             50
           /    \
         20      30

```

Now the heap property is satisfied.

---

## 4. Tree Structure → Array

The tree:

```text
             20
           /    \
         50      30
        /  \
      10   40

```

is stored as:

```text
[20, 50, 30, 10, 40]

```

For index `i`:

```cpp
left  = 2 * i + 1;
right = 2 * i + 2;

```

---

## 5. Heapify Code — Max-Heap

```cpp
void heapify(vector<int>& arr, int n, int i) {

    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Find the largest among parent, left child and right child
    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If child is larger, swap and continue downward
    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

```

---

## 6. Example

Given:

```text
arr = [20, 50, 30, 10, 40]

```

Tree:

```text
             20
           /    \
         50      30
        /  \
      10   40

```

Call:

```cpp
heapify(arr, 5, 0);

```

At index `0`:

```text
20
├── 50
└── 30

```

Largest = `50`

Swap:

```text
             50
           /    \
         20      30
        /  \
      10   40

```

Now heapify the affected subtree:

```text
             50
           /    \
         20      30
        /  \
      10   40

```

`20 < 40`, so swap again:

```text
             50
           /    \
         40      30
        /  \
      10   20

```

Final array:

```text
[50, 40, 30, 10, 20]

```

Now it satisfies the **Max-Heap property**.

---

## 7. Time & Space Complexity

For one `heapify` operation:

```text
Time  → O(log N)
Space → O(log N)   // recursive call stack

```

The element can move from the root down to the leaf, which is at most the height of the heap:

```text
Height = O(log N)

```


# 8. Insertion into Max Heap
 
Suppose we have:
 
```
        55
       /  \
     54    52
    /  \
   50   53
```
 
Array:
 
```
[55, 54, 52, 50, 53]
```
 
Now insert `60`.
 
### Step 1: Put `60` at the end
 
```
        55
       /  \
     54    52
    /  \   /
   50  53 60
```
 
Array:
 
```
[55, 54, 52, 50, 53, 60]
```
 
But now:
 
```
60 > 52
```
 
❌ Heap property is broken.
 
### Step 2: Move it upward — "heapify up"
 
Swap `60` with its parent:
 
```
        55
       /  \
     54    60
    /  \   /
   50  53 52
```
 
Still:
 
```
60 > 55
```
 
So swap again:
 
```
        60
       /  \
     54    55
    /  \   /
   50  53 52
```
 
Now it's a valid max heap.
 
Insertion =
 
```
Insert at bottom
       ↓
Compare with parent
       ↓
Swap if bigger
       ↓
Keep moving UP
```
 
This is called heapify up / bubble up / sift up.
 
Time: `O(log n)`
 
```cpp
void insert(vector<int>& heap, int value) {
    // Step 1: Put the new element at the end
    heap.push_back(value);
 
    int i = heap.size() - 1;
 
    // Step 2: Heapify Up
    while (i > 0) {
        int parent = (i - 1) / 2;
 
        // Already satisfies max-heap property
        if (heap[parent] >= heap[i]) {
            break;
        }
 
        // Parent is smaller → swap
        swap(heap[parent], heap[i]);
 
        // Move upward
        i = parent;
    }
}
```
 
---
 
# 9. Deletion from Max Heap
 
Usually when we say delete from a max heap, we mean:
 
Delete the root, i.e. the maximum element.
 
Start:
 
```
        60
       /  \
     54    55
    /  \   /
   50  53 52
```
 
Array:
 
```
[60, 54, 55, 50, 53, 52]
```
 
### Step 1: Remove the root
 
We want to delete `60`.
 
But we can't simply leave the root empty.
 
So take the last element (`52`) and put it at the root:
 
```
        52
       /  \
     54    55
    /  \
   50  53
```
 
Array:
 
```
[52, 54, 55, 50, 53]
```
 
Now heap property is broken:
 
```
52 < 54
52 < 55
```
 
❌
 
### Step 2: Move it downward — "heapify down"
 
Compare `52` with its children:
 
```
     52
    /  \
   54  55
```
 
Take the larger child, `55`.
 
Swap:
 
```
        55
       /  \
     54    52
    /  \
   50  53
```
 
Now valid max heap.
 
Deletion =
 
```
Remove root
     ↓
Move last element to root
     ↓
Compare with children
     ↓
Swap with LARGER child
     ↓
Keep moving DOWN
```
 
This is called heapify down / bubble down / sift down.
 
Time: `O(log n)`
 
```cpp
void deleteMax(vector<int>& heap) {
    // If heap is empty
    if (heap.empty()) {
        return;
    }
 
    // Step 1: Move last element to root
    heap[0] = heap.back();
 
    // Remove last element
    heap.pop_back();
 
    int i = 0;
 
    // Step 2: Heapify Down
    while (true) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
 
        int largest = i;
 
        // Check left child
        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }
 
        // Check right child
        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }
 
        // Already satisfies max-heap property
        if (largest == i) {
            break;
        }
 
        // Swap with larger child
        swap(heap[i], heap[largest]);
 
        // Move downward
        i = largest;
    }
}
```
 
# 10. Heap Sort using Max Heap
 
Goal: sort the array in ascending order.
 
```
[50, 54, 52, 55, 53]
```
 
### Core idea
 
```
1. Build a Max Heap
2. Maximum is at index 0
3. Swap maximum with the last element
4. Reduce heap size
5. Heapify Down
6. Repeat
```
 
Why max heap?
 
Because every time we get the largest element, we put it at the end.
 
### C++ Code
 
```cpp
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
 
    int left = 2 * i + 1;
    int right = 2 * i + 2;
 
    // Check left child
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
 
    // Check right child
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
 
    // If parent is not the largest
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Heapify the affected subtree
        heapify(arr, n, largest);
    }
}
 
void heapSort(vector<int>& arr) {
    int n = arr.size();
 
    // Step 1: Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
 
    // Step 2: Extract maximum one by one
    for (int i = n - 1; i > 0; i--) {
 
        // Move maximum to the end
        swap(arr[0], arr[i]);
 
        // Heapify remaining heap
        heapify(arr, i, 0);
    }
}
```
 
### Let's understand the important part
 
Suppose:
 
```
[50, 54, 52, 55, 53]
```
 
**Step 1 — Build Max Heap**
 
After heapifying:
 
```
[55, 54, 52, 50, 53]
```
 
`55` is at the root.
 
**Step 2 — Put maximum at the end**
 
```
swap(arr[0], arr[i]);
```
 
So:
 
```
[55, 54, 52, 50, 53]
 ↓
[53, 54, 52, 50, 55]
```
 
Now `55` is in its final position.
 
We don't touch it anymore.
 
The active heap is only:
 
```
[53, 54, 52, 50] | [55]
```
 
That's why we call:
 
```
heapify(arr, i, 0);
```
 
Notice `i`, not `n`.
 
We're saying: "Only heapify the remaining part."
 
Then:
 
```
[54, 53, 52, 50] | [55]
```
 
Extract `54`:
 
```
[50, 53, 52] | [54, 55]
```
 
Heapify:
 
```
[53, 50, 52] | [54, 55]
```
 
Eventually:
 
```
[50, 52, 53, 54, 55]
```
 
### 🔥 The connection with what you just learned
 
You can think of Heap Sort as repeatedly doing Delete Max, except instead of actually deleting the maximum, we swap it to the end.
 
```
DELETE MAX:
 
root → remove
last element → root
heapify down
 
 
HEAP SORT:
 
root → swap with last
reduce heap size
heapify down
```
 
That's the whole trick.
 
### Complexity
 
```
Build Max Heap     → O(n)
Heapify × n times  → O(n log n)
 
Total              → O(n log n)
Space              → O(1)
```
 
One sentence to remember:
 
Heap Sort = Build Max Heap → repeatedly move the maximum to the end → heapify the remaining heap.






---


<div align="center">
  <h1>
    HEAP on Pairs - Notes
  </h1>
</div>


## 1. Priority Queue basics 

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

## 2. Heap on pairs 

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


<div align="center">
  <h1>
    <sub><img width="35" height="35" alt="icons8-document-50" src="https://github.com/user-attachments/assets/58e5d1e9-0de7-44ef-815c-99667496f527"></sub>
    Heap Problem Solving Template
  </h1>
</div>

## Step 1 — Decide the heap type from the problem signal

Match the question to a pattern before writing anything. The heap type is rarely the "obvious" one, so lock in the syntax right away.

| Signal | Heap | Declaration |
|---|---|---|
| Kth **largest** element | min-heap, size K | `priority_queue<int, vector<int>, greater<int>> pq;` |
| Kth **smallest** element | max-heap, size K | `priority_queue<int> pq;` |
| Repeated max, no K limit | max-heap | `priority_queue<int> pq;` |
| Repeated min, no K limit | min-heap | `priority_queue<int, vector<int>, greater<int>> pq;` |
| K closest points (distance) | max-heap, size K | `priority_queue<pair<int,pair<int,int>>> pq;` |
| Top-K frequent elements | min-heap, size K | `priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;` |
| Merge K sorted lists | min-heap | `priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;` |
| Running median | max-heap + min-heap | `priority_queue<int> lo; priority_queue<int, vector<int>, greater<int>> hi;` |

---

## Step 2 — Build the heap element

What you push depends on what you're comparing, not just what you're storing.

**Distance-based** (e.g. K closest points):
```cpp
int dist = x * x + y * y;
pair<int, pair<int,int>> elem = {dist, {x, y}};
```

**Frequency-based** (e.g. top-K frequent elements):
```cpp
unordered_map<int,int> freq; // build this first with a pass over input
pair<int,int> elem = {freq[val], val};
```

**Index-tracking** (e.g. merge K sorted lists):
```cpp
// pair<value, listIndex> so you know which list to pull from next
pair<int,int> elem = {lists[i][0], i};
```

**Custom struct** (when you need more than 2 fields):
```cpp
struct Node {
    int val, row, col;
    bool operator<(const Node& other) const {
        return val > other.val; // ">" makes this behave like a min-heap
    }
};
priority_queue<Node> pq;
```

---

## Step 3 — Initial push (heap not yet full)

While the heap has fewer than K elements, push unconditionally.

```cpp
if ((int)pq.size() < k) {
    pq.push(elem);
}
```

---

## Step 4 — Conditional push once heap is at capacity

Once size == K, every new element competes with the current top.

```cpp
else if (elem.first < pq.top().first) {   // flip the sign for max-heap logic
    pq.pop();       // evict the weakest candidate
    pq.push(elem);  // push the stronger one
}
// else: skip — current element doesn't beat what's already in the heap
```

---

## Step 5 — Pop to build the answer

```cpp
vector<int> result;
while (!pq.empty()) {
    result.push_back(pq.top().second); // .second for pairs, top() for raw values
    pq.pop();
}
reverse(result.begin(), result.end()); // only if order matters
```

---

## Step 6 — Edge cases & complexity

- Empty input, K = 0, or K larger than input size — handle before the loop starts
- Duplicate values/frequencies — decide if stable tie-breaking is needed
- Time: O(N log K) with a size-capped heap, O(N log N) for a full heap
- Space: O(K) or O(N), matching whichever of the above applies

---

## Full worked example — Kth largest

```cpp
#include <queue>
#include <vector>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq; // Step 1: min-heap for Kth largest

    for (int num : nums) {
        if ((int)pq.size() < k) {
            pq.push(num);              // Step 3: heap not full yet, push directly
        } else if (num > pq.top()) {
            pq.pop();                  // Step 4: evict smallest
            pq.push(num);              // push the stronger candidate
        }
    }

    return pq.top(); // Step 5: top of a size-K min-heap = Kth largest overall
    // Step 6: assumes k <= nums.size(), no dedup needed for this variant
}
```

---

## Interview framing

State brute force first — sort descending and index `[k-1]`, O(N log N) — then pivot to the heap approach and explain the O(N log K) win when K is much smaller than N.