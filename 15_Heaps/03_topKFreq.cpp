➡️ problemLinks --> https://leetcode.com/problems/top-k-frequent-elements/  &&  https://www.geeksforgeeks.org/problems/top-k-frequent-elements-in-array/1

✅ Brute Force -->  Store {frequency, element} pairs in an array/vector, sort in descending order of frequency, and take the first k elements.
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp; // Count frequency
        for (int num : nums) {
            mpp[num]++;
        }
        
        vector<pair<int, int>> arr; // Store {frequency, element}
        for (auto it : mpp) {
            arr.push_back({it.second, it.first});
        }
        
        sort(arr.rbegin(), arr.rend());// Sort in descending order of frequency

        vector<int> ans;// Take first k elements
        for (int i = 0; i < k; i++) {
            ans.push_back(arr[i].second);
        }
        return ans;
    }
};

Time Complexity : 
- Frequency counting → O(n)
- Sorting            → O(n log n)
- Taking k elements  → O(k)
- Overall → O(n log n)

Space Complexity : O(n)

✅ Better Approach --> class Solution {
public:
    struct Compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second; // Max heap based on frequency
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequency
        unordered_map<int, int> mpp;
        for (int num : nums) {
            mpp[num]++;
        }
        // Step 2: Max heap of {element, frequency}
        priority_queue<pair<int, int>,vector<pair<int, int>>,Compare> pq;
        
        // Step 3: Push all elements into heap
        for (auto it : mpp) {
            pq.push({it.first, it.second});
        }

        // Step 4: Take top k frequent elements
        vector<int> ans;
        while (k--) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};

Time Complexity : O(n) + O(n log n) + O(k log n)= O(n log n)

Space Complexity : O(n) for the frequency map + O(n) for the heap = O(n)

✅ Optimized Approach --> class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minMinHeap;

      unordered_map<int, int> mpp;
      for(auto i : nums) mpp[i]++; // insert all with their freqency

      for(auto i : mpp){
        int element = i.first; 
        int freq = i.second;
        pair<int, int> currEle = {freq, element}; // make sure to Keep frequency first as the min heap prioritizes 
        if(minMinHeap.size() < k){                // cause pair comparison checks `.first` before `.second`
            minMinHeap.push(currEle);
            continue;
        }
        else{
            if(currEle.first > minMinHeap.top().first){
                minMinHeap.pop();
                minMinHeap.push(currEle);
            }else{
                continue; //currEle.first < minMinHeap.top().first, means current is more smaller than the top, which in smallest in the heap & we want max, so this current is the most useless element just skip it
            } 
        }
      }
      vector<int> ans;
      while(!minMinHeap.empty()){               //extract heap elements, and there will be only k elements as we 
        ans.push_back(minMinHeap.top().second); // don't allow heap to extend by poping while finding greater
        minMinHeap.pop();
      }
      return ans;
    }
};

Time Complexity : O(n) + O(n log k) + O(k log k) ≈ O(n log k)

Space Complexity : O(n + k)  ≈ O(n)



Note :: to understand GFG version better, check the code in 15_Heaps/04_topKWords.cpp

✅ GFG Version --> class Solution {
	public:
	vector<int> topKFreq(vector<int> &nums, int k) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > minMinHeap;
		
		unordered_map<int, int> mpp;
		for (auto i : nums) mpp[i]++; // insert all with their freqency
		
		for (auto i : mpp) {
			int element = i.first;
			int freq = i.second;
			pair<int, int> currEle = {freq, element}; // make sure to Keep frequency first as the min heap prioritizes
			if (minMinHeap.size() < k) { // cause pair comparison checks `.first` before `.second`
				minMinHeap.push(currEle);
				continue;
			}
			else {
				if (currEle.first > minMinHeap.top().first ||
				(currEle.first == minMinHeap.top().first && currEle.second > minMinHeap.top().second)) {
					minMinHeap.pop();
					minMinHeap.push(currEle);
				} else {
					continue; // currEle.second < minMinHeap.top().first, means current is more smaller than the top, which in smallest in the heap & we want max, so this current is the most useless element just skip it
				}
			}
		}
		vector<int> ans;
		while (!minMinHeap.empty()) { // extract heap elements, and there will be only k elements as we
			ans.push_back(minMinHeap.top().second); // don't allow heap to extend by poping while finding greater
			minMinHeap.pop();
		}
		reverse(ans.begin(), ans.end());
		return ans;
		
	}
};

Time Complexity : O(n) + O(n log k) + O(k log k) ≈ O(n log k)

Space Complexity : O(n + k)  ≈ O(n)


✅ Company Tags -->  Amazon - asked 25 times in the last 6 months
Google - asked 9 times in the last 6 months
Bloomberg - asked 5 times in the last 6 months
Meta - asked 4 times in the last 6 months
Microsoft - asked 3 times in the last 6 months
tcs - asked 3 times in the last 6 months
Walmart Labs - asked 3 times in the last 6 months
Nvidia - asked 2 times in the last 6 months
American Express - asked 2 times in the last 6 months
Apple - asked 2 times in the last 6 months
TikTok - asked 2 times in the last 6 months
SoFi - asked 2 times in the last 6 months
Visa - asked 2 times in the last 6 months
Snowflake - asked 2 times in the last 6 months
eBay - asked 2 times in the last 6 months