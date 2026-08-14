➡️ problemLinks --> https://leetcode.com/problems/online-stock-span/  &&  https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

✅ Brute Force -->  
class StockSpanner {
    vector<int> arr;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        arr.push_back(price);
        int cnt = 1;
        for(int i = arr.size() -2; i>=0;i--){
            if(arr[i]<=price) cnt++;
            else break;
        }
        return cnt;
    }
};

Time Complexity : O(n^2)
Space Complexity : O(n)

✅ Optimized Approach --> class StockSpanner { 
    stack<pair<int,int>> st; 
    int indx = -1; 

public: 
    StockSpanner() { 
        indx = -1; 
    } 
     
    int next(int price) { 
        indx++; // Current price gets the next index: 0, 1, 2, ...

        // Monotonic decreasing stack:
        // Remove all previous prices <= current price.
        // Why? They can never become the PGE for any future larger/equal price.
        // Example: [100, 80, 60] -> price = 70 -> remove 60.
        while(!st.empty() && st.top().first <= price){ 
            st.pop(); 
        } 

        // After popping, stack.top() is the Previous Greater Element (PGE).
        // Store -1 if no greater element exists.
        int PGEindx =  st.empty() ? -1 : st.top().second; 

        // Span = current index - PGE index.
        // If PGE doesn't exist: indx - (-1) = indx + 1 (entire range).
        // Example: index 5, PGE index 1 -> span = 5 - 1 = 4.
        int ans = indx - PGEindx; 

        // Store {price, index} so this price can act as PGE for future prices.
        // IMPORTANT: Don't clear the stack — it carries useful previous elements forward.
        st.push({price,indx}); 

        return ans; 
    } 
     
}; 
/*
    INTUITION:
    -----------

    For every incoming price, find its Previous Greater Element (PGE).

    PGE = nearest previous price strictly greater than current price.

    Once PGE is found:
        Stock Span = current index - PGE index

    Example:
        prices = [100, 80, 60, 70, 60, 75]
        For 75: PGE = 80 at index 1 -> span = 5 - 1 = 4


    WHY MONOTONIC STACK?
    --------------------

    We don't search backwards every time.

    Instead, maintain a decreasing stack of:
        {price, index}

    If current price >= stack.top().price:
        pop it because it can no longer be useful as a PGE.

    After all smaller/equal prices are removed:
        stack.top() = nearest Previous Greater Element.


    WHY DON'T WE CLEAR THE STACK?
    ------------------------------

    The stack stores previous prices that are still useful for future
    PGE queries.

    Example:
        [100, 80, 60] -> stack keeps all three because each can be
        the PGE for some future smaller price.


    COMPLEXITY:
    -----------

    Each element is pushed once and popped at most once.

    Time  : O(n) total / amortized O(1) per next() call
    Space : O(n)
*/

Time Complexity : O(≈ 2N) = O(n) amortized — each element is pushed once + popped at most once (≈ 2n operations);

Space Complexity : O(n)

✅ Company Tags -->  Flipkart Accolite Amazon Microsoft Samsung Adobe NPCI

