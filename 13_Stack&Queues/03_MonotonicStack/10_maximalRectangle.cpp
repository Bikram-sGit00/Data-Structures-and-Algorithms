➡️ problemLinks --> https://leetcode.com/problems/maximal-rectangle/  &&  https://www.geeksforgeeks.org/problems/max-rectangle/1

✅ Optimized Approach --> class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int element = heights[st.top()];
                st.pop();
                int NSE = i; // index of current element , for that we're doing this stuff
                int PSE = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, (element * (NSE - PSE - 1)));
            }
            st.push(i);
        }
        while (!st.empty()) {
            int element = heights[st.top()];
            st.pop();
            int NSE = n; // index of current element , for that we're doing this stuff
            int PSE = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, (element * (NSE - PSE - 1)));
        }
        return maxArea;
    }


    int maximalRectangle(vector<vector<char>>& matrix) {

    int rows = matrix.size();          // Example: 3 rows → rows = 3
    int columns = matrix[0].size();    // Example: [1 0 1] → columns = 3

    vector<int> heights(columns, 0);   // One bar per column → [0,0,0]
    int ans = 0;                       // Stores maximum rectangle found


    for (int i = 0; i < rows; i++) {   // i = current row

        for (int j = 0; j < columns; j++) { // j = current column

            if (matrix[i][j] == '1')
                heights[j]++;          // '1' → increase column height

            else
                heights[j] = 0;       // '0' → break streak, height = 0
        }

        // Example:
        // row 0: 1 0 1 → heights = [1,0,1]
        // row 1: 1 1 1 → heights = [2,1,2]
        int area = largestRectangleArea(heights);

        // Compare current histogram's max with previous answer
        ans = max(ans, area);
    }

    return ans;                         // Final maximum rectangle
}

Time Complexity : O(m*n) where m is the number of rows and n is the number of columns in the matrix.

Space Complexity : O(n) where n is the number of columns in the matrix.

✅ Company Tags -->  Flipkart Amazon Microsoft Samsung MakeMyTrip Directi Intuit Google