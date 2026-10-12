# Apply Operations on Array to Maximize Sum of Squares - [Leetcode](https://leetcode.com/problems/apply-operations-on-array-to-maximize-sum-of-squares/description/?envType=daily-question&envId=2026-10-12)

## Approach: Greedy + Bit Counting

### Intuition
Instead of choosing numbers directly, count how many numbers contain each set bit.

- `count[b]` stores how many numbers have bit `b` set.
- For each of the `k` numbers we construct, use every bit whose count is greater than `0`.
- Decrease the count after using a bit, so it cannot be reused more times than it appears in the original array.
- Add the square of each constructed number to the answer, taking modulo `10^9 + 7`.

**Why greedy works:** Constructing numbers with the highest possible available bits maximizes the sum of squares.

### Visual Example

Suppose:

```text
nums = [2, 1, 3], k = 2

Binary representation:
2 = 010
1 = 001
3 = 011
```

Count the set bits:

```text
Bit 2: 0 occurrences
Bit 1: 2 occurrences
Bit 0: 3 occurrences
```

Construct the numbers greedily:

```text
First number:  011 = 3
Second number: 011 = 3

Answer = 3² + 3² = 18
```

## Code (C++)

```cpp
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int MOD = 1e9 + 7;

        // Count how many numbers have each bit set.
        vector<int> count(32, 0);

        for(auto num : nums){
            for(int b = 0; b < 32; b++){
                if(num & (1 << b)){
                    count[b]++;
                }
            }
        }

        long long result = 0;

        // Greedily construct k numbers with the largest
        // possible set bits.
        while(k--){
            long long curr = 0;

            for(int b = 0; b < 32; b++){
                if(count[b] > 0){
                    count[b]--;          // Use this bit once.
                    curr = (curr | (1 << b));
                }
            }

            // Add the square of the constructed number.
            result = (result + (curr * curr)) % MOD;
        }

        return result;
    }
};
```

## Complexity Analysis

Let `n` be the size of `nums`.

- **Time Complexity:** \(O(32n + 32k) = O(n+k)\), since we process 32 bits per number and per constructed value.
- **Space Complexity:** \(O(32) = O(1)\), because the bit-count array has a fixed size.
