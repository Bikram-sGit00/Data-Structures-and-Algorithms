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


✅ Optimized Approach --> 

✅ Company Tags -->  VMWare Flipkart Accolite Amazon Microsoft