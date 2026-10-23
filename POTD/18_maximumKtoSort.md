# 3644. Maximum K to Sort a Permutation - [Leetcode](https://leetcode.com/problems/maximum-k-to-sort-a-permutation/description/?envType=daily-question&envId=2026-10-23)

## Approach: Bitwise AND of Mismatched Elements

### Intuition

We are given a permutation `nums` of numbers from `0` to `n - 1`. We need to find the maximum value of `k` that allows the permutation to be sorted using the allowed operations.

**Key observation:** If an element is already at its correct index, we ignore it. For every misplaced element (`nums[i] != i`), we perform a bitwise AND with `k`.

- Initialize `k = -1`, whose binary representation has all bits set (for a 32-bit integer, `11111111...11111111`).
- For every misplaced element, update `k = k & nums[i]`.
- If all elements are already in their correct positions, return `0`.

Bitwise AND keeps a bit set only when that bit is set in **both** numbers.

### Dry Run

Consider:

```cpp
nums = [0, 3, 2, 1]
```

| Index `i` | `nums[i]` | Condition | Value of `k` |
|---|---:|---|---:|
| 0 | 0 | Correct position | -1 |
| 1 | 3 | Misplaced | `-1 & 3 = 3` |
| 2 | 2 | Correct position | 3 |
| 3 | 1 | Misplaced | `3 & 1 = 1` |

**Final answer: `1`**

Only the misplaced elements (`3` and `1`) contribute to the AND operation.

### C++ Code

```cpp
class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k = -1; //"11111" all bits set

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i){
                k = k & nums[i];
            }
        }

        return k == -1 ? 0 : k;
    }
};
```

### Complexity Analysis

Let `n` be the size of `nums`.

- **Time Complexity: `O(n)`** — We traverse the array once.
- **Auxiliary Space: `O(1)`** — We use only the variable `k`, without any additional data structure.

### Interview Takeaway

This is a **bit manipulation** approach. Instead of sorting the array or using extra space, we identify the misplaced elements and combine them using bitwise AND.

The solution is optimal in time complexity because every element must be checked at least once, giving a lower bound of `O(n)` for this approach.



# ✅ Company Tags (2026 Data)

> **`Amazon`**
