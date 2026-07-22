➡️ problemLinks --> https://leetcode.com/problems/divide-two-integers/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;

        bool sign = true;
        if(dividend < 0 && divisor > 0) sign = false;
        if(divisor < 0 && dividend > 0) sign = false;

        long n = labs((long)dividend);
        long d = labs((long)divisor);
        long ans = 0; //that we will subtract from dividend

        while(n >= d){
            int cnt = 0;
            while(n >= (d << (cnt+1))){
                cnt++;
            }
            ans += 1L << cnt; // 2^cnt
            n -= (d << cnt);
        }

        if(ans == (1L<<31) && sign) return INT_MAX;
        if(ans == (1L<<31) && !sign) return INT_MIN;
        return sign ? ans : (-ans);
    }
};

// Time Complexity: O(log^2(n))
// Space Complexity: O(1)

✅ Company Tags --> Microsoft