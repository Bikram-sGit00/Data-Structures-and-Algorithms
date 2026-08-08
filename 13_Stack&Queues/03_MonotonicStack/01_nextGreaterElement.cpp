➡️ problemLinks --> https://leetcode.com/problems/next-greater-element-i/  &&  https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1

✅ Brute Force --> class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {

        int n = arr.size();
        vector<int> ans(n, -1);

        for(int i = 0; i < n; i++) {

            for(int j = i + 1; j < n; j++) {

                if(arr[j] > arr[i]) {
                    ans[i] = arr[j];
                    break;
                }
            }
        }

        return ans;
    }
};

Time Complexity : O(n^2)
Space Complexity : O(n)

✅ Optimized Approach --> class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {

        stack<int> st;
        vector<int> NGE(arr.size());

        // Traverse RIGHT → LEFT because NGE lies on the right
        for(int i = arr.size() - 1; i >= 0; i--) {

            // Remove useless candidates:
            // <= current can NEVER be a greater element
            while(!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }

            // After popping, top = nearest greater element
            // Example: [4, 5] → NGE(4) = 5
            if(st.empty()) {
                NGE[i] = -1;
            } 
            else {
                NGE[i] = st.top();
            }

            // Current becomes a candidate for elements on its left
            st.push(arr[i]);
        }

        return NGE;
    }
};

Time Complexity : O(2n) , cause while loop can run for total n times in worst case, so O(n+n) = O(2n) = O(n)
Space Complexity : O(n) + O(n) = O(2n) = O(n) , cause we are using stack and vector of size n

✅ Leetcode Version --> class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int> st;
        unordered_map<int, int> mpp;
        vector<int> ans;

        // nums2 = MAIN array → find NGE for every element
        // Traverse RIGHT → LEFT because NGE exists on the right
        for(int i = nums2.size() - 1; i >= 0; i--) {

            // Eliminate useless candidates:
            // <= current can NEVER be the next greater element
            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            // Stack top = nearest greater element after removing useless ones
            // Example: nums2 = [1,3,4,2] → NGE(1) = 3
            if(st.empty()) {
                mpp[nums2[i]] = -1;
            }
            else {
                mpp[nums2[i]] = st.top();
            }

            // Current may be the NGE for elements to its left
            st.push(nums2[i]);
        }

        // nums1 = QUERY array → fetch precomputed NGE from the map
        // Example: mpp[4] = -1, mpp[1] = 3
        for(auto x : nums1) {
            ans.push_back(mpp[x]);
        }

        return ans;
    }
};

Time Complexity : O(n + m) , cause we are traversing both arrays once, where n = nums1.size() and m = nums2.size()
Space Complexity : O(n + m) , cause we are using stack and map of size m and vector of size n

✅ Company Tags --> Flipkart Amazon Microsoft MakeMyTrip Adobe 