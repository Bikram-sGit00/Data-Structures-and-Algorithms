➡️ problemLinks --> https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

✅ Optimized Approach --> class Solution {
	public:
	class Node {
	   public:  // by default everything will get private, which will cause error into comparator
		int val;
		int row;
		int col;
		
// 		Node(int val, int row, int col) {// Can't declear member and parameter both same name so
// 			this -> val = val;        this->row = row;
// 			this -> row = row;          ↑          ↑
// 			this -> col = col;        member    parameter
// 		}

    Node(int val, int row, int col) 
        : val(val), row(row), col(col) {} // another clean way
    };
    
    struct cmp {
        bool operator()(const Node& a, const Node& b) {
            return a.val > b.val;
        }
    };
    
	vector<int> mergeArrays(vector<vector<int>> &mat) {
		priority_queue<Node, vector<Node>, cmp> minHeap;
		vector<int> ans;
		int n = mat.size();
		int m = mat[0].size();
		for(int i = 0; i < n; i++){ // insert first element of every row
		    minHeap.push({mat[i][0], i, 0});// {value, row, colloum}
		}
		while(!minHeap.empty()){
		    Node element = minHeap.top();
		    minHeap.pop();
		    int value = element.val;
		    int row = element.row;
		    int col = element.col;
		    
		    ans.push_back(value); // store the min value
		    if(col < m - 1){ // move to next value if have 
		        minHeap.push({mat[row][col + 1], row, col + 1});
		    }
		}
		return ans;
	}
};


Time Complexity : O(n log k) where n is the total number of elements in all arrays and k is the number of arrays.

Space Complexity : O(k), excluding ans array

✅ Company Tags -->  VMWare Flipkart Amazon Microsoft Citrix