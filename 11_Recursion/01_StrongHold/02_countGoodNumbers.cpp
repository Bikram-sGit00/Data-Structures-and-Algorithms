➡️ problemLinks --> https://leetcode.com/problems/count-good-numbers/ && https://www.geeksforgeeks.org/problems/count-good-numbers/1

✅ Optimized Approach --> class Solution {
public:
    
    // Modulo constant given in the problem
    const long long mod = 1e9 + 7;

    // Binary exponentiation function (similar structure to your myPow)
    long long fastPower(long long base, long long exp) {
        
        // This will store the final answer
        long long ans = 1;

        // If exponent is negative (not needed here, but keeping structure similar)
        // In countGoodNumbers, exponent will never be negative.
        if (exp < 0)
            exp = -1 * exp;

        // Run until exponent becomes 0
        while (exp > 0) {
            
            // If exponent is odd
            if (exp % 2 == 1) {
                
                // Multiply one instance of base
                ans = (ans * base) % mod;

                // Reduce exponent by 1 to make it even
                exp = exp - 1;
            }
            else {
                // If exponent is even
                // Square the base
                base = (base * base) % mod;

                // Halve the exponent
                exp = exp / 2;
            }
        }

        return ans;
    }

    int countGoodNumbers(long long n) {

        // Number of even indices (0-based indexing)
        long long evenCount = (n + 1) / 2;

        // Number of odd indices
        long long oddCount = n / 2;

        // Even index → 5 choices
        long long evenWays = fastPower(5, evenCount);

        // Odd index → 4 choices
        long long oddWays = fastPower(4, oddCount);

        // Multiply both and take modulo
        long long result = (evenWays * oddWays) % mod;

        return (int)result;
    }
};

// Time Complexity: O(log n) due to the fastPower function
// Space Complexity: O(1) as we are using only a constant amount of space.

✅ Company Tags -->  