➡️ problemLinks --> 

✅ Brute Force --> class Solution {
public:
    vector<int> nextGreater(vector<int>& arr) {

        int n = arr.size();
        vector<int> NGE(n, -1);

        // For every element, scan the next n-1 positions circularly
        for(int i = 0; i < n; i++) {

            // j = distance from current element
            // % n makes the index wrap around the array
            for(int j = 1; j < n; j++) {

                int index = (i + j) % n;

                // First greater element found = NGE
                if(arr[index] > arr[i]) {
                    NGE[i] = arr[index];
                    break;
                }
            }
        }

        return NGE;
    }
};

Time Complexity :  O(n^2)

Space Complexity : O(n)

✅ Optimized Approach --> 

Time Complexity :  

Space Complexity :  

✅ Company Tags -->  
