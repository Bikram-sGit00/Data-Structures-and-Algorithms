➡️ problemLinks --> https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1

✅ with ans variable --> class Solution {
	public:
	void nearlySorted(vector<int>& arr, int k) {
		priority_queue<int, vector<int>, greater<int>> minHeap;
		vector<int> ans ;
		
		for (int i = 0; i <= k; i++) {
			minHeap.push(arr[i]); // store first k+1 elements in minHeap
		}
		
		for (int i = k + 1 ; i < arr.size(); i++) { // 
			ans.push_back(minHeap.top()); // now if array was [6, 2, 3, 12, 5, 8, ...] & k = 2, then
			minHeap.pop(); //                minHeap -> [2, 6, 3] & top will be 2, so we push 2 in ans -> [2]
			minHeap.push(arr[i]); //         after that remove 2 from minHeap & push 12 in minHeap -> [3, 6, 12]
		}
		
		while (!minHeap.empty()) {
			ans.push_back(minHeap.top()); // now after arranging all, if last few are correctly sorted e.g. [7, 8, 9] then we push them in ans -> [2, 3, 5, 6, 7, 8, 9]
			minHeap.pop();
		}
		
		for (int i = 0; i < arr.size(); i++) {
			arr[i] = ans[i]; // copy the sorted elements back to the original array
		}
	}
};



✅ Company Tags -->  Google