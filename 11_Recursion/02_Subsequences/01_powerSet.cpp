➡️ problemLinks --> 

✅ Optimized Approach ( GFG Version ) --> class Solution {
  public:
    vector<string> AllPossibleStrings(string s) {
        
        // Length of input string
        int n = s.length();
        
        // Total subsequences = 2^n (using bit shift, 1<<n is faster than pow(2,n))
        // each bit position represents include(1) or exclude(0) for that character
        int total = 1 << n;
        
        // Vector to store all valid subsequences
        vector<string> subsequences;
        
        // Start from 1 (not 0) to SKIP empty subsequence (selector=0 means no bits set = no characters selected)
        for(int selector = 1; selector < total; selector++){
            
            // Fresh empty string for EACH selector (reset every iteration, else previous chars carry over)
            string subSeq = "";
            
            // Check each character position
            for(int i = 0; i < n; i++){
                
                // (1<<i) creates a number with ONLY i-th bit set
                // & (bitwise AND) checks if i-th bit is ON in selector
                // if ON → include s[i], if OFF → skip
                // NOTE: use & not && (& checks bits, && checks true/false)
                if(selector & (1 << i)){
                    subSeq += s[i];
                }
            }
            
            // Push the formed subsequence string (NOT the vector itself)
            subsequences.push_back(subSeq);
        }
        
        // Sort alphabetically before returning (expected output is in sorted order)
        sort(subsequences.begin(), subsequences.end());
        
        return subsequences;
    }
};

// Time Complexity: O(n * 2^n) because we generate 2^n subsequences and each subsequence can take O(n) time to construct.
// Space Complexity: O(n * 2^n) because we store all subsequences and each subsequence can be up to length n.

✅ Optimized Approach ( LeetCode Version ) --> class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        // Length of input array
        int n = nums.size();
        
        // Total subsets = 2^n (1<<n is faster than pow(2,n))
        // Each bit position represents include(1) or exclude(0) for that number
        int total = 1 << n;
        
        // Stores all subsets (each subset is a vector<int>, so result is vector of vectors)
        vector<vector<int>> result;
        
        // Start from 0 (NOT 1) to INCLUDE empty subset []
        // selector=0 means all bits OFF = no elements selected = empty subset []
        for(int selector = 0; selector < total; selector++){
            
            // Fresh empty vector for EACH selector (each selector = one unique subset)
            vector<int> subset;
            
            // Check each index position
            for(int i = 0; i < n; i++){
                
                // (1<<i) creates number with ONLY i-th bit set
                // & (bitwise AND) checks if i-th bit is ON in selector
                // if ON → include nums[i] in this subset
                // NOTE: always use & not && (&& is for true/false, & is for bit checking)
                if(selector & (1 << i)){
                    subset.push_back(nums[i]);  // push integer into subset vector
                }
            }
            
            // Push completed subset into result
            // push_back(subset) not push_back(result) — push the subset, not the result itself
            result.push_back(subset);
        }
        
        // No sorting needed — problem accepts any order
        return result; 
    }
};

// Time Complexity: O(n * 2^n) because we generate 2^n subsets and each subset can take O(n) time to construct.
// Space Complexity: O(n * 2^n) because we store all subsets and each subset can be up to length n.

✅ Company Tags -->  