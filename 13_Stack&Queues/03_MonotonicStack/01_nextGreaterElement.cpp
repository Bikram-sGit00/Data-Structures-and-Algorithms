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


