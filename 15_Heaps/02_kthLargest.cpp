➡️ problemLinks --> https://leetcode.com/problems/kth-largest-element-in-an-array/  &&  https://www.geeksforgeeks.org/problems/kth-largest-element5034/1

✅ Brute Force -->  will be to sort the array and return the kth largest element. arr[n-k]

Time Complexity : O(n log n)

Space Complexity : O(1)

✅ Better Approach --> class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        
        // Keep the k largest elements seen so far;
        // the heap's top is the smallest among them, i.e., the kth largest.
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        // Create the initial group of k elements.
        for(int i = 0; i < k; i++){
            minHeap.push(arr[i]);
        }
        
        // If a larger element appears, remove the smallest element
        // from our k-largest group and include the new larger element.
        for(int i = k; i < arr.size(); i++){
            if(minHeap.top() < arr[i]){
                minHeap.pop();
                minHeap.push(arr[i]);
            }
        }
        
        // The smallest element among the k largest elements is the kth largest.
        return minHeap.top();
    }
};

Time Complexity : O(n log k)    

Space Complexity : O(k) 

✅ Optimized Approach --> will be to use Quick Select Algorithm.

Time Complexity : O(n) average, O(n^2) worst case

Space Complexity : O(1)

✅ Company Tags -->  Meta - asked 9 times in the last 6 months
Google - asked 7 times in the last 6 months
Amazon - asked 5 times in the last 6 months
tcs - asked 3 times in the last 6 months
Bloomberg - asked 3 times in the last 6 months
Microsoft - asked 2 times in the last 6 months
Infosys - asked 2 times in the last 6 months
LinkedIn - asked 2 times in the last 6 months
Spotify - asked 2 times in the last 6 months
Flipkart - asked 2 times in the last 6 months
TikTok - asked 2 times in the last 6 months