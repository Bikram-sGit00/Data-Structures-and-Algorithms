➡️ problemLinks --> https://leetcode.com/problems/assign-cookies/  &&  https://www.geeksforgeeks.org/problems/assign-cookies/1

✅ Optimized Approach --> class Solution {
public:
    int findContentChildren(vector<int>& child, vector<int>& cookie) {

        // Greedy idea:
        // Always try to satisfy the smallest child with the smallest
        // cookie that can satisfy them.
        //
        // Why Greedy?
        // If a small cookie can satisfy a child, giving it to them
        // wastes less cookie size and keeps bigger cookies available
        // for children who may need them.
        
        int left = 0; // will traverse the child array
        int right = 0; // will traverse the cookie array

        // Sort both arrays so we can greedily match
        // the smallest possible child with the smallest possible cookie.
        sort(child.begin(),child.end());
        sort(cookie.begin(),cookie.end());

        while(left < child.size() && right < cookie.size()){

            // If the current cookie can satisfy the current child,
            // this child is satisfied and we can move on to the next child.
            if(child[left] <= cookie[right]){
                left++;
            }

            // Both arrays are sorted, so if the current cookie cannot satisfy the current child, it cannot satisfy any future children either. So move ahead.
            right++;
        }

        // 'left' represents the number of children we successfully satisfied.
        return left;
    }
};


- Sorting child   → O(n log n)
- Sorting cookie  → O(m log m)
- While loop      → O(n + m)

Overall Complexity → O(n log n + m log m)

Space Complexity : O(1)

✅ Company Tags -->  