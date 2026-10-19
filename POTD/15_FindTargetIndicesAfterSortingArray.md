# 2089. Find Target Indices After Sorting Array - [Leetcode](https://leetcode.com/problems/find-target-indices-after-sorting-array/description/?envType=daily-question&envId=2026-10-19)

## Problem Statement

Given an integer array `nums` and an integer `target`, sort the array in non-decreasing order and return a list of all indices where `nums[i] == target`.

The returned indices must be in increasing order.

**Example**

```text
Input: nums = [1, 2, 5, 2, 3], target = 2

Sorted Array: [1, 2, 2, 3, 5]

Output: [1, 2]
```

The target `2` appears at indices `1` and `2` after sorting.

---

## Approach 1: Sorting + Linear Search (Baseline)

### Intuition

1. Sort the array so that all elements are in non-decreasing order.
2. Traverse the sorted array.
3. Whenever an element equals `target`, store its index in `ans`.
4. Return `ans`.

### Dry Run

**Input:** `nums = [1, 2, 5, 2, 3]`, `target = 2`

After sorting:

```text
Index:  0  1  2  3  4
Nums:  [1, 2, 2, 3, 5]
          ↑  ↑
       Target indices
```

| Index `i` | `nums[i]` | Condition | `ans` |
|---:|---:|---|---|
| 0 | 1 | Not equal to 2 | `[]` |
| 1 | 2 | Match | `[1]` |
| 2 | 2 | Match | `[1, 2]` |
| 3 | 3 | Not equal to 2 | `[1, 2]` |
| 4 | 5 | Not equal to 2 | `[1, 2]` |

**Final answer:** `[1, 2]`

### Code

```cpp
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;

        // Sort the array so target indices are determined by sorted order.
        sort(nums.begin(), nums.end());

        // Traverse the sorted array and collect every matching index.
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target) ans.push_back(i);
        }

        return ans;
    }
};
```

### Complexity Analysis

- **Time Complexity:** \(O(n \log n)\) for sorting + \(O(n)\) for traversal = **\(O(n \log n)\)**.
- **Auxiliary Space:** Typically \(O(\log n)\) for the sorting implementation's stack.
- **Output Space:** \(O(k)\), where \(k\) is the number of occurrences of `target`.

Note: This is a straightforward sorting-based baseline, not brute force in the strict sense. It works, but sorting is unnecessary if we only need the target indices.

---

## Approach 2: Count Smaller Elements, Then Find Targets

### Intuition

After sorting, every element smaller than `target` must appear before every occurrence of `target`.

Therefore, the number of elements smaller than `target` tells us the **first target index**.

For example:

```text
nums = [1, 2, 5, 2, 3]
target = 2

Elements smaller than 2: [1]
count = 1

Sorted positions of target: [1, 2]
```

We do not need to sort the array.

1. Count how many elements are smaller than `target`.
2. Traverse the array again.
3. Whenever an element equals `target`, push the current `count` into `ans`, then increment `count`.

### Dry Run

**Input:** `nums = [1, 2, 5, 2, 3]`, `target = 2`

**First loop — count smaller elements**

| Element | Is it smaller than 2? | `count` |
|---:|---|---:|
| 1 | Yes | 1 |
| 2 | No | 1 |
| 5 | No | 1 |
| 2 | No | 1 |
| 3 | No | 1 |

Now, `count = 1`, so the first target index will be `1`.

**Second loop — collect target indices**

| Element | Action | `ans` | `count` |
|---:|---|---|---:|
| 1 | Skip | `[]` | 1 |
| 2 | Push 1, increment | `[1]` | 2 |
| 5 | Skip | `[1]` | 2 |
| 2 | Push 2, increment | `[1, 2]` | 3 |
| 3 | Skip | `[1, 2]` | 3 |

**Final answer:** `[1, 2]`

### Code

```cpp
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        int count = 0;

        // Count elements smaller than target.
        // This count is the first index where target will appear after sorting.
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < target) count++;
        }

        // Find each occurrence of target and assign its sorted index.
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                ans.push_back(count);
                count++;
            }
        }

        return ans;
    }
};
```

### Complexity Analysis

- **Time Complexity:** \(O(n) + O(n) = O(n)\), because we traverse the array twice.
- **Auxiliary Space:** \(O(1)\), excluding the output vector.
- **Output Space:** \(O(k)\), where \(k\) is the number of occurrences of `target`.

---

## Approach 3: Count Smaller Elements + Count Target Occurrences (Optimal)

### Intuition

We can simplify Approach 2 by counting two things in a single traversal:

- `countOfLess`: The number of elements smaller than `target`.
- `countOfTarget`: The number of elements equal to `target`.

After sorting, all target elements occupy consecutive indices.

The first target index is `countOfLess`, and the total number of target indices is `countOfTarget`.

Therefore, the answer consists of every index from:

\[
\text{countOfLess}
\quad\text{to}\quad
\text{countOfLess}+\text{countOfTarget}-1
\]

We can directly generate those indices without sorting or scanning the array a second time.

### Dry Run

**Input:** `nums = [1, 2, 5, 2, 3]`, `target = 2`

**Step 1: Count smaller elements and target occurrences.**

| Element | Smaller than 2? | Equal to 2? | `countOfLess` | `countOfTarget` |
|---:|---|---|---:|---:|
| 1 | Yes | No | 1 | 0 |
| 2 | No | Yes | 1 | 1 |
| 5 | No | No | 1 | 1 |
| 2 | No | Yes | 1 | 2 |
| 3 | No | No | 1 | 2 |

After the first loop:

```text
countOfLess   = 1
countOfTarget = 2
```

**Step 2: Generate the target indices.**

```text
Start index = countOfLess = 1
End boundary = countOfLess + countOfTarget = 3

i = 1 → ans = [1]
i = 2 → ans = [1, 2]
```

The loop stops when `i == 3` because the upper boundary is exclusive.

**Final answer:** `[1, 2]`

### Code

```cpp
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        int countOfLess = 0;
        int countOfTarget = 0; 

        // Count elements smaller than target and occurrences of target.
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < target) countOfLess++;
            if(nums[i] == target) countOfTarget++;
        }

        // Target elements occupy consecutive indices starting at countOfLess.
        for(int i = countOfLess; i < countOfLess + countOfTarget; i++){
            ans.push_back(i);
        }

        return ans;
    }
};
```

### Complexity Analysis

- **Time Complexity:** \(O(n) + O(k) = O(n)\), where \(n\) is the array size and \(k\) is the number of target occurrences. Since \(k \le n\), the overall complexity is \(O(n)\).
- **Auxiliary Space:** \(O(1)\), excluding the output vector.
- **Output Space:** \(O(k)\), because the answer contains exactly \(k\) indices.

---

## Approach Comparison

| Approach | Time Complexity | Auxiliary Space | Main Idea |
|---|---|---|---|
| 1. Sorting + Search | \(O(n \log n)\) | \(O(\log n)\) typically | Sort, then collect matching indices |
| 2. Count + Search | \(O(n)\) | \(O(1)\) | Count smaller elements, then assign indices to matches |
| 3. Count + Generate | \(O(n)\) | \(O(1)\) | Count smaller elements and target occurrences, then generate consecutive indices |

*Output space of \(O(k)\) is excluded from the auxiliary-space column.*

---

## Which Approach Should You Use in an Interview?

**Approach 3 is the recommended solution.**

Why?

- It avoids sorting the array.
- It traverses the input array only once to collect the necessary counts.
- It uses those counts to construct the answer directly.
- Its \(O(n)\) time complexity is optimal because, in the general case, every element must be examined to determine the correct result.

Approach 2 is also optimal in asymptotic time and is perfectly acceptable in an interview. Approach 3 is a little cleaner because it separates counting from index generation rather than updating a single counter while scanning for matches.

**Interview explanation:**

"After sorting, all elements smaller than the target appear before it, and all occurrences of the target occupy consecutive indices. I count the elements smaller than the target to find the starting index and count the target occurrences to determine how many indices to return. I can then generate the answer directly in linear time without sorting."

**Pattern to remember:** When a problem asks for indices after sorting, check whether you can derive their positions using counts instead of actually sorting the array.