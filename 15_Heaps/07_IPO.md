<div align="center">

<h1> IPO — Maximize Capital </h1>
<p> ➡️ problemLink --> (https://leetcode.com/problems/ipo/) </p>
</div>



## 🔹 Overview

You have `k` chances to choose projects.

Each project has:

```text
capital[i] = money required
profits[i] = money earned
```

You can only start a project if:

```text
capital[i] <= current w
```

After completing it:

```text
w += profit
```

**Goal:** Maximize `w` after at most `k` projects.

### Smallest Example

```text
w = 0
capital = [0, 1]
profits = [1, 2]

→ choose {0,1} → w = 1
→ choose {1,2} → w = 3
```

---

## 🔹 Why Heap?

At every step, there may be multiple projects that we can currently afford.

Among those affordable projects, we should always choose the one with the **maximum profit**.

So:

```text
Affordable projects
        ↓
   Max Heap
        ↓
Maximum profit
```

We use:

- `sort()` → process projects in increasing order of required capital.
- `maxHeap` → always get the **maximum profit** among currently affordable projects.

### Example

```text
w = 2

Affordable profits = [1, 5, 3]

maxHeap
   ↓
   5  ← choose this
```

After taking profit `5`:

```text
w = 2 + 5 = 7
```

Now more projects may become affordable.

---

## 🔹 Optimal Approach

1. Store every project as:

```text
{capital, profit}
```

2. Sort all projects by required capital.

3. Add every project satisfying:

```text
capital <= w
```

   into the max heap.

4. The max heap gives the project with the **largest profit**.

5. Add that profit to `w`.

6. Repeat this at most `k` times.

### Key Idea

```text
Sort by CAPITAL
        ↓
Find all currently affordable projects
        ↓
Put their PROFITS in maxHeap
        ↓
Take maximum PROFIT
        ↓
Increase w
        ↓
Repeat
```

---

## 🔹 Code

```cpp
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = capital.size();

        vector<pair<int, int>> project;

        for(int i = 0; i < n; i++){
            project.push_back({capital[i], profits[i]}); // {0,1}, {1,2} ...
        }

        sort(project.begin(), project.end());

        priority_queue<int> maxHeap;

        int indx = 0;

        while(k--){

            // Add every project we can currently afford
            while(indx < n){
                if(project[indx].first > w) break;

                maxHeap.push(project[indx].second);
                indx++;
            }

            // No affordable project → cannot increase capital
            if(maxHeap.empty()) return w;

            // Take the project with maximum profit
            int profit = maxHeap.top();
            maxHeap.pop();

            // Example: w = 2, profit = 5 → w = 7
            w += profit;
        }

        return w;
    }
};
```

---

## 🔹 Line-by-Line Explanation

### Store projects

```cpp
project.push_back({capital[i], profits[i]});
```

Example:

```text
capital = [0, 1]
profits = [1, 2]

project = {{0,1}, {1,2}}
            ↑  ↑
         capital profit
```

---

### Sort by capital

```cpp
sort(project.begin(), project.end());
```

Example:

```text
Before:
{{2,5}, {0,1}, {1,3}}

After:
{{0,1}, {1,3}, {2,5}}
```

---

### Check affordability

```cpp
if(project[indx].first > w) break;
```

Example:

```text
w = 3

project[indx] = {5,10}

5 > 3 → cannot afford it → break
```

Because projects are sorted by capital, later projects will also require at least this much capital.

---

### Put profit into max heap

```cpp
maxHeap.push(project[indx].second);
```

Example:

```text
Affordable:

{0,1}
{2,5}
{3,2}

maxHeap = [5, 2, 1]
```

Therefore:

```cpp
maxHeap.top()
```

gives:

```text
5
```

---

### Take maximum profit

```cpp
int profit = maxHeap.top();
maxHeap.pop();
```

Example:

```text
maxHeap = [5, 2, 1]

top = 5
```

We choose the largest available profit.

---

### Increase capital

```cpp
w += profit;
```

Example:

```text
w = 3
profit = 5

w = 3 + 5 = 8
```

Now projects requiring up to `8` capital can become available.

---

## Time Complexity

### Sorting

```text
O(n log n)
```

### Heap

Every project is pushed at most once:

```text
O(n log n)
```

At most `k` projects are popped:

```text
O(k log n)
```

Therefore:

```text
TC = O(n log n + k log n)
```

Since `k <= n`:

```text
TC = O(n log n)
```

---

## Space Complexity

`project` stores `n` projects:

```text
O(n)
```

`maxHeap` can contain up to `n` profits:

```text
O(n)
```

Therefore:

```text
SC = O(n)
```

---

## Final Complexity

```text
TC → O(n log n)
SC → O(n)
```

### Pattern to Remember

> **Sort by the constraint (capital), then use a max heap to greedily choose the best available value (profit).**
