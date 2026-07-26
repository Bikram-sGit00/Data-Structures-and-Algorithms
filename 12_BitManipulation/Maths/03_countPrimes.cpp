➡️ problemLinks --> https://leetcode.com/problems/count-primes/

✅ Optimized Approach --> Sieve of Eratosthenes
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        int cnt = 0;
        vector<int> primes(n , 1);
        primes[0] = 0;
        primes[1] = 0; // 0 and 1 are not prime so that's why
        for (int i = 2; i * i < n; i++) {
            if (primes[i] == 1) {
                for (int j = i * i; j < n; j += i) {
                    primes[j] = 0;
                }
            }
        }
        for (int i = 2; i < n; i++) {
            if (primes[i] == 1) {
                cnt++;
            }
        }
        return cnt;
    }
};

// Time Complexity -->O(n) + O(nlog logn) , Since (nlog logn) grows faster than n, we keep only the dominant term: O(nlog logn)
// Space Complexity --> O(n)

✅ Company Tags -->  