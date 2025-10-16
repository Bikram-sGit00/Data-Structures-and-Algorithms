➡️ problemLinks --> https://leetcode.com/problems/sqrtx/

✅ Brute Force -->  class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        for(long long i = 1; i <= x; i++){
            if(i * i == x) return i;
            if(i * i > x) return i - 1;
        }
        return -1;
    }
};


✅ Optimized Approach --> class Solution {
public:
    int mySqrt(int x) {
        int low = 1;
        int high = x;
        while (low <= high) {
            long long mid = (static_cast<long long>(low) + high) / 2;
            long long ans = (mid * mid);
            if (ans <= x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }
};

// Time Complexity --> O(log n)
// Space Complexity --> O(1)

✅ Company Tags -->  VMWare Flipkart Accolite Amazon Microsoft