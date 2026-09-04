➡️ problemLinks --> https://leetcode.com/problems/top-k-frequent-words/description/

✅ Optimized Approach --> again we have to find most frequent, but this time they said they want the lexicographically smaller word in case of same frequency, so we have to make a custom comparator for the min heap, which will keep the smaller frequency at the top, and to find small what "what's the trick ?" yes max heap, so we design a MIN-MAX Heap.

class Solution { 
public: 
    struct cmp{ 
        bool operator()(pair<int, string> &a, pair<int, string> &b){ 
            if(a.first != b.first){ 
                return a.first > b.first;  // Smaller frequency stays at the top
            } 
            return a.second < b.second;    // For same frequency, larger word stays at the top
        } 
    }; 
    
    vector<string> topKFrequent(vector<string>& words, int k) { 
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> minMaxHeap; 
 
        unordered_map<string, int> mpp; 
        for(auto it : words){ 
            mpp[it]++; // Count frequency of each word
        } 
 
        for(auto it : mpp){ 
            string str = it.first; 
            int freq = it.second; 
            pair<int, string> currStr = {freq, str}; // Keep frequency first for pair comparison
 
            if(minMaxHeap.size() < k){ 
                minMaxHeap.push(currStr); // Fill heap until it contains k elements
                continue; 
            }
            else{ 
                // Replace top if current word is more frequent or better lexicographically
                if(currStr.first > minMaxHeap.top().first ||  
                (currStr.first == minMaxHeap.top().first && currStr.second < minMaxHeap.top().second)){ 
                    minMaxHeap.pop(); 
                    minMaxHeap.push(currStr); 
                }
                else{ 
                    continue; // Current word is less useful, so skip it
                } 
            } 
        } 

        // vector<string> ans;
        // while(!minMaxHeap.empty()){
        //     ans.push_back(minMaxHeap.top().second);
        //     minMaxHeap.pop();
        // }
        // reverse(ans.begin(), ans.end());, also valid but extra reverse operation
 
        vector<string> ans(k); 
        for(int i = k - 1; i >= 0; i--){ 
            ans[i] = minMaxHeap.top().second; // Extract from worst to best, so fill answer from back
            minMaxHeap.pop(); 
        } 
        
        return ans; 
    } 
};

Time Complexity : O(n) + O(n log k) + O(k log k) ≈ O(n log k)

Space Complexity : O(n + k)  ≈ O(n)

✅ Company Tags -->  