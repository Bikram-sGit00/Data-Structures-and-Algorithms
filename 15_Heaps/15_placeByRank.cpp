➡️ problemLinks -->  https://leetcode.com/problems/rank-transform-of-an-array/description/  &&  https://www.geeksforgeeks.org/problems/convert-an-array-to-reduced-form1101/1

✅ Optimized Approach 1 --> class Solution { 
public: 
    vector<int> arrayRankTransform(vector<int>& arr) { 
         
        // Copy the array because we need the sorted order
        // but still need the original positions/values.
        map<int, int> mpp; 
        vector<int> sortArr = arr; 
        sort(sortArr.begin(), sortArr.end()); 
 
        int rank = 1; 

        // Traverse the sorted array.
        // Assign rank only to unique elements.
        // This makes duplicate elements get the same rank.
        for(int i = 0; i < sortArr.size(); i++){ 
            if(mpp.find(sortArr[i]) == mpp.end()){ 
                mpp[sortArr[i]] = rank++; 
            } 
        } 

        // Replace every original element with its rank.
        for(int i = 0; i < arr.size(); i++){ 
            arr[i] = mpp[arr[i]]; 
        } 

        return arr; 
    } 
};

Time Complexity : O(n log n)

Space Complexity : O(n)


✅ Optimized Approach 2 --> class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i = 0; i < arr.size(); i++){
            minHeap.push(arr[i]);
        }
        unordered_map<int, int> mpp;
        int rank = 1;
        while(!minHeap.empty()){
            // if(mpp.find(minHeap.top()) == mpp.end()){
            //     mpp[minHeap.top()] = rank++;
            //     minHeap.pop();
            // }
            // else minHeap.pop(); // also pop for equal element

            int num = minHeap.top();
            minHeap.pop();
            if(mpp.find(num) == mpp.end()){
                mpp[num] = rank++;
            }
            
        }
        for(int i = 0; i < arr.size(); i++){
            arr[i] = mpp[arr[i]]; 
        }
        return arr;
    }
};

Time Complexity : O(n log n)
Space Complexity : O(n)


✅ Company Tags -->  