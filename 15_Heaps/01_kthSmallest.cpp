➡️ problemLinks --> 

✅ Brute Force -->  will be to sort the array and return the kth largest element.

Time Complexity : O(n log n)

Space Complexity : O(1)

✅ Better Approach --> class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        for(int i = 0; i < k; i++){
            minHeap.push(arr[i]);
        }
        for(int i = k; i < arr.size(); i++){
            if(minHeap.top() < arr[i]){
                minHeap.pop();
                minHeap.push(arr[i]);
            }
        }
        return minHeap.top();
    }
};

Time Complexity : O(n log k)

Space Complexity : O(k)

✅ Optimized Approach --> 

Time Complexity : 

Space Complexity : 

✅ Company Tags -->  