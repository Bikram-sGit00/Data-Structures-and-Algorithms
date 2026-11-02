# 462. Minimum Moves to Equal Array Elements II - [Leetcode](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/?envType=daily-question&envId=2026-11-02)

## Problem

Given an integer array `nums`, return the minimum number of moves required to make all array elements equal.

In one move, you can increment or decrement any element by `1`.

The goal is to find the minimum total number of moves.

### Example

**Input:**
```cpp
nums = [1, 2, 3]
```

**Output:**
```cpp
2
```

**Explanation:**

Make all elements equal to `2`.

- `1 → 2` = 1 move
- `2 → 2` = 0 moves
- `3 → 2` = 1 move

Total = **2 moves**.

---

## Approach 1: Sorting + Median (Basic)

### Intuition

The key observation is that the **median minimizes the sum of absolute differences** between all elements.

After sorting the array, the middle element is the median.

Why median?

Suppose we want to make all elements equal to some value `x`.

The total moves are:

```cpp
abs(nums[0] - x) + abs(nums[1] - x) + ...
```

Choosing the median minimizes this total.

For an odd-sized array, there is one middle element.

For an even-sized array, any value between the two middle elements minimizes the total. We can simply choose `nums[n/2]`.

### Code

```cpp
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end()); // Sort the array

        int moves = 0;

        // Choose the middle element (median)
        for(int i = 0; i < nums.size(); i++){
            moves += abs(nums[i] - nums[n/2]);
        }

        return moves;
    }
};
```

### Complexity Analysis

- **Time Complexity:** O(n log n)
  - Sorting takes O(n log n).
  - Traversing the array takes O(n).

- **Space Complexity:** O(1) auxiliary space for the typical in-place sorting implementation (ignoring sorting's stack space).

---

## Approach 2: Sorting + Two Pointers

### Intuition

We can optimize the calculation slightly by observing that after sorting, elements on the left and right sides of the median can be processed in pairs.

For example:

```text
nums = [1, 2, 3, 4, 5]
median = 3
```

Pair the elements from both ends:

```text
1  2  3  4  5
↑           ↑
```

Both elements need to move towards the median.

We can calculate their moves together:

```cpp
abs(nums[i] - mid) + abs(nums[n-i-1] - mid)
```

Here:

- `i` represents the left-side element.
- `n - i - 1` represents the corresponding right-side element.

We only need to iterate through the first half of the array.

**Important:** If the array has an odd number of elements, the median is already equal to the target, so it contributes zero moves. If it has an even number, both middle elements are included in the pairing.

### Code

```cpp
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int moves = 0;
        int mid = nums[n/2]; // Store the median

        // Process elements from both ends
        for(int i = 0; i < n/2; i++){
            moves += abs(nums[i] - mid);

            // n - i - 1 gives us the corresponding right-side element
            moves += abs(nums[n - i - 1] - mid);
        }

        return moves;
    }
};
```

### Complexity Analysis

- **Time Complexity:** O(n log n)
  - Sorting takes O(n log n).
  - Pairing elements takes O(n).

- **Space Complexity:** O(1) auxiliary space, ignoring sorting's stack space.

### What changed from Approach 1?

Instead of traversing the entire array, we traverse only its first half and calculate the moves of two elements in every iteration.

The overall time complexity remains the same.

---

## Approach 3: Using `nth_element()` (Optimal)

### Intuition

In the previous approaches, we sorted the entire array just to find the median.

But do we really need the entire array to be sorted?

**No!**

We only need the correct median element at index `n/2`.

C++ provides an STL function called `nth_element()` for this purpose.

### What is `nth_element()`?

```cpp
nth_element(nums.begin(), nums.begin() + n/2, nums.end());
```

It rearranges the array so that:

- The element at index `n/2` contains the same value it would have after fully sorting the array.
- Every element before that position is less than or equal to the median.
- Every element after that position is greater than or equal to the median.
- The remaining elements are not necessarily sorted.

**Example:**

Before:

```text
[5, 1, 3, 2, 4]
```

After `nth_element()` with index `2`, one possible arrangement is:

```text
[2, 1, 3, 5, 4]
       ↑
     Median
```

Notice that the array is not fully sorted, but the correct median (`3`) is at index `2`.

This is exactly what we need!

### Code

```cpp
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();

        // Places the correct median at index n/2.
        // The remaining elements are not fully sorted.
        // Average time complexity: O(n).
        nth_element(nums.begin(), nums.begin() + n/2, nums.end());

        int moves = 0;
        int mid = nums[n/2]; // Store the median

        // Calculate moves from both ends
        for(int i = 0; i < n/2; i++){
            moves += abs(nums[i] - mid);

            // n - i - 1 gives us the corresponding right-side element
            moves += abs(nums[n - i - 1] - mid);
        }

        return moves;
    }
};
```

### Complexity Analysis

- **Time Complexity:** 
  - `nth_element()` takes O(n) on average.
  - Calculating moves takes O(n).
  - Overall: **O(n) average**.

- **Space Complexity:** O(1) auxiliary space in the typical implementation.

---

## Dry Run (Approach 3)

**Input:**

```cpp
nums = [1, 10, 2, 9]
```

### Step 1: Find the median

```cpp
nth_element(nums.begin(), nums.begin() + 2, nums.end());
```

One possible arrangement:

```text
[1, 2, 9, 10]
       ↑
    mid = 9
```

```cpp
mid = nums[n/2]; // 9
```

### Step 2: Calculate moves using pairs

Here:

```text
n = 4
mid = 9
```

| i | Left element | Right element | Moves |
|---|---:|---:|---:|
| 0 | 1 | 10 | 8 + 1 = 9 |
| 1 | 2 | 9 | 7 + 0 = 7 |

Total:

```text
moves = 9 + 7 = 16
```

**Output:**
```cpp
16
```

---

## Approach Comparison

| Approach | Technique | Time Complexity |
|---|---|---|
| 1 | Sorting + Full Traversal | O(n log n) |
| 2 | Sorting + Two Pointers | O(n log n) |
| 3 | `nth_element()` + Two Pointers | O(n) average |

## Interview Takeaway

The important pattern in this problem is **Median + Absolute Difference**.

Remember these points:

1. The median minimizes the sum of absolute differences.
2. Sorting allows us to find the median in O(n log n).
3. Two pointers let us calculate moves from both ends together, but do not improve the overall complexity.
4. `nth_element()` finds the correct median without sorting the entire array.

**Interview recommendation:** Approach 3 is a good choice when you know `nth_element()`. It gives O(n) average time instead of O(n log n).

### How to Recognize This Pattern?

Whenever a problem asks you to minimize:

```cpp
sum of abs(nums[i] - x)
```

where you can choose the target value `x`, think about the **median**.

When you only need the K-th smallest element rather than a fully sorted array, consider `nth_element()`.

# ✅ Company Tags (2026 Data)

> **`Amazon`** 
> **`Google`** 
> **`Microsoft`** 
> **`Myntra`**
> **`paypal`**
> **`tcs`** 


