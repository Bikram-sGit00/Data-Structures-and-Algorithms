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

✅ Better Approach -->  will use a hash map to store the frequency of prefix XORs and count subarrays with XOR equal to K
class Solution {
public:
    int subarrayXor(vector<int>& arr, int k) {
        int n = arr.size();
        int count = 0;
        // Three nested loops: i (start), j (end), k (for XOR calculation)
        for (int i = 0; i < n; i++) {
            int xorSum = 0;
            for (int j = i; j < n; j++) {
                xorSum ^= arr[j];
                if (xorSum == k) {
                    count++;
                }
            }
        }
        return count;
    }
};
// Time Complexity: O(N^2) - due to two nested loops
// Space Complexity: O(1) - no extra space used

✅ Optimized Approach --> 

✅ Company Tags -->  