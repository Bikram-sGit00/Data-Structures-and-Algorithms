➡️ problemLinks --> https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/  &&  https://www.geeksforgeeks.org/problems/bit-difference-1587115620/1

✅ Optimized Approach -->  Will do XOR of given two inputs as opposite bits will return 1 and then we will count the set bits to know minimum flips required.
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start ^ goal;
        int cnt = 0;
        while (ans != 0) {
            ans = ans & (ans-1);
            cnt++;
        }
        return cnt;
    }
};

// Time Complexity: O(k) , where k is the number of set bits
// worst case : O(log n)
// Space Complexity: O(1)
