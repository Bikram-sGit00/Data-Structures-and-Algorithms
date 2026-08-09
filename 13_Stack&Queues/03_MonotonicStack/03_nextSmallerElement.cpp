➡️ problemLinks --> https://www.geeksforgeeks.org/problems/immediate-smaller-element1142/1


NGE                          NSE

Right → Left                 Right → Left

Pop <= current               Pop >= current

Decreasing Stack             Increasing Stack

Top = Greater                Top = Smaller

TC → O(2N)                    TC → O(2N)
SC → O(N)                    SC → O(N)



✅ Optimized Approach --> class Solution {
public:
    vector<int> nextSmallerEle(vector<int>& arr) {

        stack<int> st;
        vector<int> NSE(arr.size());

        // Traverse RIGHT → LEFT because NSE lies on the right
        for(int i = arr.size() - 1; i >= 0; i--) {

            // Remove useless candidates:
            // >= current can NEVER be the next smaller element
            while(!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }

            // After popping, top = nearest smaller element
            if(st.empty()) {
                NSE[i] = -1;
            }
            else {
                NSE[i] = st.top();
            }

            // Current becomes a candidate for elements on its left
            st.push(arr[i]);
        }

        return NSE;
    }
};

Time Complexity : O(2n)
Space Complexity : O(n)

✅ Company Tags -->  Flipkart Amazon
