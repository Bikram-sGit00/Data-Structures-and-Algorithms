➡️ problemLinks --> https://leetcode.com/problems/kth-largest-element-in-a-stream/description/

✅ Optimized Approach --> class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this -> k = k;
        for (auto it : nums) {
            minHeap.push(it); // temporarily allow heap to extend k + 1 size
            if (minHeap.size() > k) { // now again shrink to k , tha's how we will not loose anything, e.g 
                minHeap.pop();        // heap = [5, 8, 10], insert(2), Now heap = [2, 5, 8, 10], so 2 will get poped
            }                         // But if we don't have used this approach heap will became [2, 8, 10] ❌
        }
    }

    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > k){
            minHeap.pop();
        }
        return minHeap.top();
    }
};

Time Complexity :: O(n log k) for constructor and O(log k) for add() function, every push and pop takes O(log k)

Space Complexity :: O(k) for storing k elements in the heap


✅ GFG Version --> https://www.geeksforgeeks.org/problems/kth-largest-element-in-a-stream2220/1
class Solution {
	public:
	vector<int> kthLargest(vector<int>& arr, int k) {
		priority_queue<int, vector<int>, greater<int>> minHeap;
		vector<int> ans;
		for (auto it : arr) {
			minHeap.push(it); // temporarily allow heap to extend k + 1 size
			if (minHeap.size() > k) { // now again shrink to k , tha's how we will not loose anything, e.g
				minHeap.pop(); // heap = [5, 8, 10], insert(2), Now heap = [2, 5, 8, 10], so 2 will get poped
			}
			if(minHeap.size() < k){
			    ans.push_back(-1);
			}
			else ans.push_back(minHeap.top());
			
		}
		return ans;
	}
};

Time Complexity :: O(n log k) 

Space Complexity :: O(k) auxiliary

Output :: O(n)

✅ Company Tags -->  Flipkart Amazon Microsoft OYORooms Hike Walmart Cisco Adobe