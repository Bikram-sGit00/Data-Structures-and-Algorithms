➡️ problemLinks --> 

✅ Optimized Approach --> class Solution {
	public:
	vector<int> primeFactors(int n) {
		vector<int> ans;
		for (int i = 2; i*i <= n; i++) {
			while (n%i == 0) {
				ans.push_back(i);
				n = n/i;
			}
		}
		if (n != 1)
			ans.push_back(n);
		return ans;
	}
};
// Time Complexity: O(sqrt(n) + log n) , Since sqrt(n) grows much faster than log n, we simplify it to: O(sqrt(n))
// Space Complexity : O(1)

✅ Company Tags -->  