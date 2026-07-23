➡️ problemLinks --> https://leetcode.com/problems/single-number/description/  &&  

✅ Brute Force -->  class Solution {
public:
    // Function to find the single non-repeating element using brute force
    int getSingleElement(vector<int>& arr) {
        int n = arr.size();

        // Loop through every element
        for (int i = 0; i < n; i++) {
            int num = arr[i]; // current element to check
            int cnt = 0;

            // Count occurrences of this element
            for (int j = 0; j < n; j++) {
                if (arr[j] == num)
                    cnt++;
            }

            // If it occurs only once, return it
            if (cnt == 1) return num;
        }

        // This line should never be reached
        return -1;
    }
};

// Time Complexity: O(n^2) , where n is the size of the array
// Space Complexity: O(1)

✅ Better Approach --> class Solution {
public:
    // Function to find the single non-repeating element using a hash array
    int getSingleElement(vector<int>& arr) {
        int n = arr.size();

        // Step 1: Find the maximum value in the array
        int maxi = arr[0];
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, arr[i]);
        }

        // Step 2: Declare and initialize hash array of size maxi+1
        vector<int> hash(maxi + 1, 0);

        // Step 3: Count the frequency of each number
        for (int i = 0; i < n; i++) {
            hash[arr[i]]++;
        }

        // Step 4: Find the element that occurs exactly once
        for (int i = 0; i < n; i++) {
            if (hash[arr[i]] == 1)
                return arr[i];
        }

        return -1; // fallback, shouldn't occur in valid input
    }
};

// Time Complexity: O(n) , where n is the size of the array
// Space Complexity: O(maxi) , where maxi is the maximum value in the array

✅ Optimized Approach --> class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int xorr=0; // Initialize xorr to 0
            for(int i=0;i<nums.size();i++){ // Iterate through the array
                // XOR the current element with xorr
                // The result will be the number that appears once
                // because all other numbers appear twice and cancel each other out
              xorr= xorr^nums[i];
            }
            return xorr;
        }
};

// Time Complexity: O(n) , where n is the size of the array`
// Space Complexity: O(1)

✅ Company Tags -->  NPCI Ola Cabs Amazon Microsoft Codenation Qualcomm



