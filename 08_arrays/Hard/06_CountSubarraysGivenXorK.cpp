➡️ problemLinks --> https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1

✅ Brute Force -->  will iterate through all possible subarrays and count those with XOR equal to K using 3 nested loops
class Solution {
public:
    int subarrayXor(vector<int>& arr, int k) {
        int n = arr.size();
        int count = 0;
        // Three nested loops: i (start), j (end), k (for XOR calculation)
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int xorSum = 0;
                for (int k_idx = i; k_idx <= j; k_idx++) {
                    xorSum ^= arr[k_idx];
                }
                if (xorSum == k) {
                    count++;
                }
            }
        }

        return count;
    }
};
// Time Complexity: O(N^3) - due to three nested loops
// Space Complexity: O(1) - no extra space used

✅ Better Approach --> 

✅ Optimized Approach --> 

✅ Company Tags -->  