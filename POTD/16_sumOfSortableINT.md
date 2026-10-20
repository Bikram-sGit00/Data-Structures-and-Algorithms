# Sortable Integers — [Leetcode](https://leetcode.com/problems/sum-of-sortable-integers/?envType=daily-question&envId=2026-10-20)

## Problem Overview

Given an array `nums`, determine the sum of all valid subarray sizes `k` such that:

1. `k` divides `n`, the size of the array.
2. Divide `nums` into consecutive blocks of size `k`.
3. Every block must be a cyclic rotation of the corresponding block in the sorted array.

A cyclic rotation means moving elements from the beginning of an array to the end, while preserving their relative order.

### Example

```text
nums = [5, 8]
sortedArr = [5, 8]
n = 2
```

**For `k = 1`:**

```text
nums blocks:      [5] [8]
sortedArr blocks: [5] [8]

Both blocks match → Valid
Contribution = 1
```

**For `k = 2`:**

```text
nums blocks:      [5, 8]
sortedArr blocks: [5, 8]

The entire block matches → Valid
Contribution = 2
```

Therefore,

```text
Answer = 1 + 2 = 3
```

---

## Approach 1: Brute Force

### Intuition

Instead of using KMP, we can check every possible cyclic rotation directly.

1. Sort the original array.
2. Try every block size `k` from `1` to `n`.
3. Skip `k` if `n % k != 0`.
4. Divide both arrays into blocks of size `k`.
5. For each pair of blocks, try every possible rotation and check whether the blocks match.
6. If every block matches, add `k` to the answer.

### Code

```cpp
class Solution {
public:
    bool isRotateable(vector<int>& v1, vector<int>& v2) {
        int k = v1.size();

        for(int shift = 0; shift < k; shift++) {
            bool match = true;

            for(int i = 0; i < k; i++) {
                if(v1[i] != v2[(i + shift) % k]) {
                    match = false;
                    break;
                }
            }

            if(match) return true;
        }

        return false;
    }

    int sortableIntegers(vector<int>& nums) {
        vector<int> sortedArr = nums;
        sort(sortedArr.begin(), sortedArr.end());

        int n = nums.size();
        int result = 0;

        for(int k = 1; k <= n; k++) {
            if(n % k != 0) continue;

            bool valid = true;

            for(int start = 0; start < n; start += k) {
                vector<int> v1(
                    nums.begin() + start,
                    nums.begin() + start + k
                );

                vector<int> v2(
                    sortedArr.begin() + start,
                    sortedArr.begin() + start + k
                );

                if(!isRotateable(v1, v2)) {
                    valid = false;
                    break;
                }
            }

            if(valid) result += k;
        }

        return result;
    }
};
```

### Complexity Analysis

Let \(d(n)\) denote the number of divisors of \(n\).

- **Time:** \(O(n\log n+n\sum_{k\mid n}k)\), with an upper bound of \(O(n^2+n\log n)\).
- **Auxiliary space:** \(O(n)\), including the sorted array and temporary blocks.

The repeated rotation checks are expensive because each block can require up to \(k\) rotations, each taking \(O(k)\) time.

---

## Approach 2: KMP Pattern Matching

### Intuition

We can optimize the rotation check using the **Knuth–Morris–Pratt (KMP)** string-matching algorithm, adapted to integer arrays.

The key observation is:

If `v1` is a cyclic rotation of `v2`, then `v1` must appear as a contiguous subarray of `v2 + v2`.

For example:

```text
v1 = [3, 4, 1, 2]
v2 = [1, 2, 3, 4]

text = v2 + v2

text = [1, 2, 3, 4, 1, 2, 3, 4]
                  └───────────┘
                  [3, 4, 1, 2]

Pattern found → Valid rotation
```

We use KMP to search for `v1` inside the doubled `v2` without repeatedly comparing elements from scratch.

### Steps

1. Create a sorted copy of `nums`.
2. Consider each possible block size `k` that divides `n`.
3. Divide the original and sorted arrays into corresponding blocks.
4. For each pair of blocks:
   - Double the sorted block by concatenating it with itself.
   - Use KMP to check whether the original block occurs inside it.
5. If all blocks pass, add `k` to `result`.

### C++ Code

```cpp
class Solution {
public:
    // Build the LPS (Longest Prefix Suffix) array for the pattern.
    // lps[i] stores the length of the longest proper prefix
    // that is also a suffix for pattern[0...i].
    void computeLPS(vector<int>& pattern, vector<int>& lps) {
        int M = pattern.size();
        int len = 0;
        lps[0] = 0;

        int i = 1;
        while (i < M) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    // Reuse the previous matching prefix.
                    // Do not move i because another match may exist.
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    // Search for the pattern inside the text using KMP.
    bool search(vector<int>& pat, vector<int>& txt) {
        int N = txt.size();
        int M = pat.size();

        vector<int> lps(M, 0);
        computeLPS(pat, lps);

        int i = 0; // index for text
        int j = 0; // index for pattern

        while (i < N) {
            if (pat[j] == txt[i]) {
                i++;
                j++;
            }

            if (j == M) {
                return true; // pattern found , return true
            } else if (i < N && pat[j] != txt[i]) {
                if (j != 0) {
                    // Shift the pattern using the LPS array
                    // instead of restarting the comparison.
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return false;
    }

    // A block is a cyclic rotation if it occurs in the doubled block.
    bool isRotateable(vector<int>& v1, vector<int>& v2){
        vector<int> text = v2;
        text.insert(end(text), v2.begin(), v2.end());
        return search(v1,text);
    }

    int sortableIntegers(vector<int>& nums) {
        // Create the fully sorted version of the array.
        vector<int> sortedArr = nums;
        sort(sortedArr.begin(), sortedArr.end());

        int n = nums.size();
        int result = 0;

        // Only block sizes that divide n can form equal-sized blocks.
        for(int k = 1; k <= n; k++){
            if(n % k != 0) continue;

            bool valid = true;

            // Check every consecutive block of size k.
            for(int start = 0; start < n; start += k){
                vector<int> v1(nums.begin() + start, nums.begin() + start + k);
                vector<int> v2(sortedArr.begin() + start, sortedArr.begin() + start + k);

                // If any block is not a cyclic rotation, k is invalid.
                if(!isRotateable(v1, v2)){
                    valid = false;
                    break;
                }
            }

            // Add k only when every corresponding block is valid.
            if(valid){
                result += k;
            }
        }
        return result;
    }
};
```

### Complexity Analysis

Let \(d(n)\) be the number of divisors of \(n\).

**1. Sorting**

Sorting the array takes \(O(n\log n)\) time.

**2. Checking each block size**

For a valid block size \(k\):

- There are \(n/k\) blocks.
- Each KMP search takes \(O(k)\) time because the pattern has length \(k\) and the doubled text has length \(2k\).
- Checking all blocks therefore takes \(O((n/k)\cdot k)=O(n)\) time.

Since there are \(d(n)\) possible block sizes, the total is:

- **Time:** \(O(n\log n+n\cdot d(n))\).
- **Auxiliary space:** \(O(n)\), including the sorted array, temporary blocks, doubled block, and LPS array.

Using \(d(n)\leq 2\sqrt n\), the overall time has an upper bound of \(O(n\sqrt n+n\log n)\).

---

## Which Approach Is Better for Interviews?

**Approach 2 — KMP is the stronger choice** when you can clearly explain the rotation property and the LPS array.

| Criterion | Brute Force | KMP |
|---|---|---|
| Rotation check | Try every shift | Search in a doubled block |
| Pattern matching | Repeated comparisons | LPS-based matching |
| Time complexity | \(O(n^2+n\log n)\) upper bound | \(O(n\,d(n)+n\log n)\) |
| Implementation | Simpler | More involved |
| Interview value | Good baseline | Better asymptotic performance |

### Interview takeaway

The key optimization is recognizing that cyclic rotation checking can be reduced to pattern matching in a doubled array. KMP avoids repeating comparisons by using information from previous matches.

The overall algorithm is **not strictly \(O(n)\)** because it checks every divisor of `n` and sorts the array first. Its time complexity is \(O(n\,d(n)+n\log n)\).

*Note:* The implementation assumes `nums` is non-empty. For an empty pattern, `computeLPS()` would access `lps[0]`, so empty input would need separate handling if the problem permits it.
