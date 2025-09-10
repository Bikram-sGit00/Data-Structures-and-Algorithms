➡️ problemLinks --> https://leetcode.com/problems/find-missing-and-repeated-values/  && https://leetcode.com/problems/set-mismatch/ && https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

✅ Brute Force -->  https://takeuforward.org/data-structure/find-the-repeating-and-missing-numbers/

✅ Better Approach --> https://takeuforward.org/data-structure/find-the-repeating-and-missing-numbers/

✅ Optimized Approach 1 --> //code for 2d array
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& a) {
        long long n = a.size();
        long long N = n * n; // total numbers = n^2

        // Expected sum of first N natural numbers
        long long SN = (N * (N + 1)) / 2;
        // Expected sum of squares of first N natural numbers
        long long S2N = (N * (N + 1) * (2 * N + 1)) / 6;

        long long S = 0, S2 = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                S += a[i][j]; // sum of elements
                S2 += static_cast<long long>(a[i][j]) * a[i][j]; // sum of squares
            }
        }

        long long val1 = S - SN;   // x - y
        long long val2 = S2 - S2N; // x^2 - y^2 = (x-y)(x+y)

        val2 = val2 / val1; // x + y

        long long x = (val1 + val2) / 2; // repeated
        long long y = x - val1;          // missing

        return {(int)x, (int)y};
    }
};

// code for 1d array
class Solution {
public:
    vector<int> findErrorNums(vector<int>& a) {
        long long n = a.size();

        long long SN = (n * (n + 1)) / 2; // expected sum 1..n
        long long S2N =
            (n * (n + 1) * (2 * n + 1)) / 6; // expected sum of squares

        long long S = 0, S2 = 0;
        for (int num : a) {
            S += num;
            S2 += 1LL * num * num;
        }

        long long val1 = S - SN;   // x - y
        long long val2 = S2 - S2N; // x^2 - y^2

        val2 /= val1; // x + y

        long long x = (val1 + val2) / 2; // duplicate
        long long y = x - val1;          // missing

        return {(int)x, (int)y};
    }
};


// Time Complexity --> O(n) for both 1D and 2D arrays
// Space Complexity --> O(1) for both 1D and 2D arrays


✅ Optimized Approach 2 --> //code for 2d array

class Solution {
public:
    vector<int> findErrorNums(vector<int>& a) {
        long long n = a.size();   // size of the array (numbers from 1 to n)
        int xr = 0;

        // STEP 1: XOR all numbers in the array and XOR with 1..n
        // Why? Because XOR cancels out matching numbers.
        // After this, xr = (missing number) ^ (repeated number)
        for (int i = 0; i < n; i++) {
            xr = xr ^ a[i];       // XOR with array element
            xr = xr ^ (i + 1);    // XOR with natural number (1..n)
        }

        // STEP 2: Find a bit (position) where missing and repeated differ.
        // Because they are different numbers, at least one bit is different.
        int bitNo = 0;
        while (1) {
            if ((xr & (1 << bitNo)) != 0) {  // check if this bit is set in xr
                break;                       // stop when we find a set bit
            }
            bitNo++;
        }

        // STEP 3: Divide numbers into two groups (based on that bit).
        // Group "zero" = numbers where bitNo is 0.
        // Group "one"  = numbers where bitNo is 1.
        int zero = 0;
        int one = 0;

        // Separate all numbers in array into zero/one group
        for (int i = 0; i < n; i++) {
            if ((a[i] & (1 << bitNo)) != 0) {
                one ^= a[i];    // XOR into "one" group
            } else {
                zero ^= a[i];   // XOR into "zero" group
            }
        }

        // Separate all numbers from 1..n into zero/one group
        for (int i = 1; i <= n; i++) {   // FIXED: should start at 1 not 0
            if ((i & (1 << bitNo)) != 0) {
                one ^= i;       // XOR into "one" group
            } else {
                zero ^= i;      // XOR into "zero" group
            }
        }

        // STEP 4: Now we have two numbers: "zero" and "one".
        // But we don't know which one is missing and which one is repeated.
        // So, check which one actually appears in array.
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == zero)   // count how many times "zero" appears
                cnt++;
        }

        // If zero doesn’t appear, then zero = missing, one = duplicate
        if (cnt == 0)
            return {zero, one};

        // Otherwise, one = missing, zero = duplicate
        return {one, zero};
    }
};

// Time Complexity --> O(4n) but if we nest the loops then ~ O(n)
// Space Complexity --> O(1)

✅ Company Tags -->  