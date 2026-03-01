➡️ problemLinks --> https://leetcode.com/problems/powx-n/ && https://www.geeksforgeeks.org/problems/powx-n/1

✅ Brute Force -->  will be iterating from 1 to n and multiplying x with itself n times. This approach has a time complexity of O(n) and space complexity of O(1).

✅ Optimized Approach --> class Solution {
public:
    double myPow(double x, int n) {
        
        // We will compute x^n using Binary Exponentiation
        // Time Complexity: O(log n)
        // Space Complexity: O(1)
        
        double ans = 1.0;        // Final result accumulator
        
        long long copyN = n;           // We store n in another variable
                                  // so that original n remains unchanged
                                  // (we need original n later to check if it was negative)

        // If exponent is negative, convert it to positive.
        // Why?
        // Because:
        //      x^(-n) = 1 / (x^n)
        // So we first compute x^|n|, and later take reciprocal.
        
        if (copyN < 0)
            copyN = -1 * copyN;  // Flips sign: (-1) * (-3) = 3
        
        // Main loop: runs until exponent becomes 0
        // Each iteration reduces exponent significantly (log n behaviour)
        
        while (copyN) {
            
            // If exponent is odd:
            // Example: 3 = 2 + 1
            // We multiply one x to answer,
            // then reduce exponent by 1 to make it even.
            
            if (copyN % 2 == 1) {   // If exponent is odd
                ans = ans * x;      // Multiply current base
                copyN = copyN - 1;  // Make exponent even
            } 
            else {
                // If exponent is even:
                // Example:
                // x^8 = (x^2)^4
                // So instead of multiplying x 8 times,
                // we square the base and halve the exponent.
                
                x = x * x;          // Square the base
                copyN = copyN / 2;  // Halve the exponent
            }
        }

        // If original exponent was negative,
        // apply reciprocal.
        
        if (n < 0)
            ans = 1.0 / ans;

        return ans;
    }
};

// Time Complexity: O(log n) due to halving the exponent in each step.
// Space Complexity: O(1) as we are using only a constant amount of space.

✅ Company Tags -->  