# 2778. Sum of Squares of Special Elements

## Approach — Check Every Index

### Intuition
An element is special if its **1-based index divides the array length `n`** without leaving a remainder.

Since C++ uses 0-based indexing, the problem's 1-based index is `i + 1`.

- If `n % (i + 1) == 0`, the element is special.
- Add the square of that element to `ans`.

### Visual Example

**Input:** `nums = [2, 7, 1, 19, 18, 3]`

Here, `n = 6`.

| 1-based index (`i + 1`) | Element | `6 % (i + 1)` | Special? |
|---:|---:|---:|:---:|
| 1 | 2 | 0 | Yes |
| 2 | 7 | 0 | Yes |
| 3 | 1 | 0 | Yes |
| 4 | 19 | 2 | No |
| 5 | 18 | 1 | No |
| 6 | 3 | 0 | Yes |

Only the elements at indices `1, 2, 3, 6` are special.

```text
nums = [ 2,  7,  1, 19, 18,  3]
        ✓   ✓   ✓   ✗   ✗   ✓

ans = 2² + 7² + 1² + 3²
    = 4 + 49 + 1 + 9
    = 63
```

### C++ Solution

```cpp
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            // Check whether the 1-based index divides n
            if(n % (i + 1) == 0)
                ans += (nums[i] * nums[i]);
        }

        return ans;
    }
};
```

### Complexity Analysis

- **Time Complexity:** `O(n)` — We traverse the array once.
- **Space Complexity:** `O(1)` — Only a constant number of extra variables are used.

### Note ::
Always distinguish between the **1-based index used by the problem** and the **0-based index used by C++**. Here, `i + 1` is used for the divisibility check, while `nums[i]` accesses the element.
