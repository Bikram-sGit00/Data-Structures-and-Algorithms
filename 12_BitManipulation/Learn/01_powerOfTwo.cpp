➡️ problemLinks --> https://leetcode.com/problems/power-of-two/  &&  https://www.geeksforgeeks.org/problems/power-of-2-1587115620/1

✅ Optimized Approach --> class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n > 0 && (n & (n - 1)) == 0)
            return true;
        else
            return false;
    }
};

// Time Complexity: O(1)
// Space Complexity: O(1)

✅ Company Tags -->  Adobe