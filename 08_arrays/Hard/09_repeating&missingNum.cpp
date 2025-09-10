➡️ problemLinks --> https://leetcode.com/problems/find-missing-and-repeated-values/  && https://leetcode.com/problems/set-mismatch/ && https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

✅ Brute Force -->  

✅ Better Approach --> 

✅ Optimized Approach --> //code for 2d array
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


✅ Company Tags -->  