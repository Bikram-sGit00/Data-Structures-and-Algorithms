➡️ problemLinks --> https://leetcode.com/problems/k-closest-points-to-origin/  &&  https://www.geeksforgeeks.org/problems/k-closest-points-to-origin--172242/1

✅ Optimized Approach --> same as other heap problems, refer readme.md for better understanding
class Solution { 
public: 
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) { 
        // Max heap stores {distance, index}
        // The farthest point stays at the top
        priority_queue<pair<int, int>> maxMaxHeap; 
        // Traverse all the points
        for (int i = 0; i < points.size(); i++) { 
            
            // Get x and y coordinates
            int x = points[i][0]; 
            int y = points[i][1]; 

            √(x1 - x2)^2 + (y1 - y2)^2 = x^2 + y^2, as origin is (0, 0)  
 
            now If (x^2+y^2) is smaller, then (sqrt{x^2+y^2}) is also smaller.
            // int distance = sqrt(pow(x,2) + pow(y,2)); so no need to calculate sqrt, just calculating square will done the work
            int distance = x * x + y * y; // can also be like "distance = (pow(x,2) + pow(y,2))" this.
            
            // Store the index of the current point
            int eleIndx = i; 
    
            // Store {distance, index} in the heap
            pair<int, int> currEle = {distance, eleIndx}; 
            
            // Push elements until heap size becomes k
            if (maxMaxHeap.size() < k) { 
                maxMaxHeap.push(currEle); 
            } else { 
                
                // If current point is closer than the farthest point
                if (currEle.first < maxMaxHeap.top().first) { 
                    
                    // Remove the farthest point
                    maxMaxHeap.pop(); 
                    
                    // Insert the current closer point
                    maxMaxHeap.push(currEle); 
                } else { 
                    // Current point is farther, so ignore it
                    continue; 
                } 
            } 
        } 
        
        // Store the k closest points
        vector<vector<int>> ans; 
        
        // Extract all points from the heap
        while (!maxMaxHeap.empty()) { 
            
            // Get the index of the point
            int indx = maxMaxHeap.top().second; 
            
            // Push the original point into the answer
            ans.push_back(points[indx]); 
            
            // Remove the point from the heap
            maxMaxHeap.pop(); 
        } 
        
        return ans; 
    } 
};

Time Complexity : O(n log k)

Space Complexity : O(k)

✅ Company Tags -->  Meta - asked 9 times in the last 6 months
Asana - asked 3 times in the last 6 months
Amazon - asked 2 times in the last 6 months
Bloomberg - asked 2 times in the last 6 months