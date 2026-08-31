➡️ problemLinks --> https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1

✅ Brute Force -->  will be to sort the array and return the kth smallest element.

Time Complexity : O(n log n)

Space Complexity : O(1)

✅ Better Approach --> class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int> heap;
        for(int i = 0; i < k; i++){
            heap.push(arr[i]);
        }
        for(int i = k; i < arr.size(); i++){
            if(heap.top() > arr[i]){
                heap.pop();
                heap.push(arr[i]);
            }
        }
        return heap.top();
    }
};

Time Complexity : O(n log k)

Space Complexity : O(k)

✅ Optimized Approach --> will be to use Quick Select Algorithm.

Time Complexity : O(n) average, O(n^2) worst case

Space Complexity : O(1)

✅ Company Tags -->  VMWare Accolite Amazon Microsoft Snapdeal Hike Adobe Google ABCO Cisco