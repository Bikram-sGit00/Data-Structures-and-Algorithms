➡️ problemLinks --> https://leetcode.com/problems/spiral-matrix/description/ && https://www.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1

These Question dose'nt have any other approach ... so why asked ? cause interviewer wants to check your Implementation skills and ability to write clean code

✅ Optimized Approach -->  The optimized approach involves using a single loop to traverse the matrix in a spiral manner. This can be achieved by maintaining four pointers (top, bottom, left, right) to keep track of the boundaries of the current layer being processed. This approach has a time complexity of O(N*M) and a space complexity of O(N*M).

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(); // No of Rows
        int m = matrix[0].size(); // No of Cols ... Basically they give us list of list & we have to figure-out container size && [0] will give us that ...
        int left = 0, right = m - 1;
        int top = 0, bottom = n - 1;
        vector<int> ans;

        while (left <= right && top <= bottom) {
            // Left --> Right
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]); // top const
            }
            top++;

            // Top --> Bottom
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;

            if (top <= bottom) {
                // Right --> left
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]); // bottom row is const
                }
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};

//Time Complexity: O(N * M) where N is the number of rows and M is the number of columns in the matrix.
//Space Complexity: O(1) for the pointers and O(N * M) for the output vector `ans` which stores the spiral order of the matrix elements.

✅ Company Tags -->  Paytm Flipkart Morgan Stanley Microsoft OYO Rooms Snapdeal D-E-Shaw MakeMyTrip Oracle MAQ Software Adobe nearbuy Nagarro BrowserStack Salesforce Zoho