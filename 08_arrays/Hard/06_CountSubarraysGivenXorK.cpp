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




// X^K = XR;
// X^K^K = XR^K; BOTH SIDE XOR K ADDED
// X = XR^K;


✅ Optimized Approach --> 
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        int xr = 0;
        map<int,int> mpp;
        mpp[xr]++; // {0,1} inserted
        int cnt = 0;
        for(int i = 0; i < arr.size(); i++){
            xr = xr^arr[i];
            int x = xr ^ k;
            cnt += mpp[x]; //mpp[x] tells how many times this value occurred before.
            mpp[xr]++; //We record the current prefix XOR xr in the map for future use.
        }
        return cnt;
    }
};

// Time Complexity: O(N) - single pass through the array
// Space Complexity: O(N) - for the hash map to store prefix XORs
 