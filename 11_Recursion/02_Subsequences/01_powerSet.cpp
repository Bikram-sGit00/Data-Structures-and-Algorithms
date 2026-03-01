➡️ problemLinks --> 

✅ Brute Force -->  

✅ Better Approach --> 

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

✅ Company Tags -->  