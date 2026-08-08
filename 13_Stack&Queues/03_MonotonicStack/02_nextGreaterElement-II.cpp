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

✅ Optimized Approach --> class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {

        int n = arr.size();
        stack<int> st;
        vector<int> NGE(n, -1);

        // Traverse 2N times → simulates the circular array
        // i % n brings the virtual index back into [0, n-1]
        for(int i = 2 * n - 1; i >= 0; i--) {

            int indx = i % n;

            // Remove useless candidates:
            // <= current can NEVER be the next greater element
            while(!st.empty() && st.top() <= arr[indx]) {
                st.pop();
            }

            // Only fill answers during the actual first pass
            // During the extra pass, we only build useful stack information
            if(i < n && !st.empty()) {
                NGE[indx] = st.top();
            }

            // Current element becomes a candidate for elements on its left
            st.push(arr[indx]);
        }

        return NGE;
    }
};

Time Complexity : O(4n)

Space Complexity : O(2n) + O(n)

✅ Company Tags --> Flipkart Amazon Microsoft
