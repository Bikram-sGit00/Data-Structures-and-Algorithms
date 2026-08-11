➡️ problemLinks --> 

✅ Brute Force -->  

Time Complexity : 

Space Complexity : 

✅ Better Approach --> 

Time Complexity : 

Space Complexity : 

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