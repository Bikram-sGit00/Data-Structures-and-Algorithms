➡️ problemLinks --> 

✅ Brute Force --> 
class Solution {
public:

    vector<int> findNSE(vector<int>& heights, int n) {
        stack<int> st;
        vector<int> NSE(n);

        for(int i = n - 1; i >= 0; i--) {
            // Remove elements >= current → need strictly smaller
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            // No smaller element → boundary is n
            NSE[i] = st.empty() ? n : st.top();

            // Store index, not element
            st.push(i);
        }

        return NSE;
    }


    vector<int> findPSE(vector<int>& heights, int n) {
        stack<int> st;
        vector<int> PSE(n);

        for(int i = 0; i < n; i++) {
            // Remove elements >= current → need strictly smaller
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            // No smaller element → boundary is -1
            PSE[i] = st.empty() ? -1 : st.top();

            // Store index, not element
            st.push(i);
        }

        return PSE;
    }


    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;

        vector<int> NSE = findNSE(heights, n);
        vector<int> PSE = findPSE(heights, n);

        for(int i = 0; i < n; i++) {

            // Width between PSE and NSE
            int width = NSE[i] - PSE[i] - 1;

            // Area = height × width
            int area = heights[i] * width;

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

Time Complexity : 2 x O(2n) + O(n) => O(5n)

Space Complexity : O(4n)

✅ Optimized Approach --> 
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();


        for (int i = 0; i < n; i++) {
            // Stack stores indexes in increasing height order
            while(!st.empty() && heights[st.top()] > heights[i]){
                int element = heights[st.top()];
                st.pop();

                int NSE = i; // Current smaller element becomes NSE
                int PSE = st.empty() ? -1 : st.top(); // After pop, top = PSE

                // Width = NSE - PSE - 1
                maxArea = max(maxArea,(element * (NSE - PSE - 1)));
                
            }
            st.push(i); // Store current index for future rectangles
        }

        // Remaining bars have no smaller element on the right
        while(!st.empty()){
                int element = heights[st.top()];
                st.pop();

                int NSE = n; // No NSE → consider boundary after last index
                int PSE = st.empty() ? -1 : st.top(); // After pop, top = PSE

                // Calculate area using the remaining width
                maxArea = max(maxArea,(element * (NSE - PSE - 1)));
        }

        return maxArea;
    }
};

Time Complexity : O(n) + O(n) ~ O(2n) ~ O(n)

Space Complexity : O(n)

✅ Company Tags -->  Microsoft Google NPCI