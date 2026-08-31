➡️ problemLinks --> https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1

✅ Brute Force -->  will be to sort the array and return the kth smallest element.

Time Complexity : O(n log n)

Space Complexity : O(1)

✅ Better Approach --> Maintain a group of the k smallest elements; whenever a smaller element appears, remove the group''s largest element and include the new smaller one.
class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        
        // Keep the k smallest elements seen so far;
        // the heap's top is the largest among them, i.e., the kth smallest.
        priority_queue<int> heap;
        
        // Create the initial group of k elements.
        for(int i = 0; i < k; i++){
            heap.push(arr[i]);
        }
        
        // Check remaining elements and replace the current largest
        // whenever a smaller element should enter our k-smallest group.
        for(int i = k; i < arr.size(); i++){
            if(heap.top() > arr[i]){
                heap.pop();
                heap.push(arr[i]);
            }
        }
        
        // The largest element among the k smallest elements is the kth smallest.
        return heap.top();
    }
};

Time Complexity : O(n log k)

Space Complexity : O(k)

✅ Optimized Approach --> will be to use Quick Select Algorithm.

Time Complexity : O(n) average, O(n^2) worst case

Space Complexity : O(1)

✅ Company Tags -->  VMWare Accolite Amazon Microsoft Snapdeal Hike Adobe Google ABCO Cisco