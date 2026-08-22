➡️ problemLinks --> https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/  &&  https://www.geeksforgeeks.org/problems/count-substring/1

✅ Brute Force -->  class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt  = 0;
        for(int i = 0; i < n; i++){    
            vector<int> hash(3,0); // Track whether a, b, c are present
            for(int j = i; j < n; j++){   // Extend the substring
                hash[s[j] - 'a'] = 1;     // Mark the current character as present
                if(hash[0]+hash[1]+hash[2] == 3) cnt += 1; // Count if a, b, c are all present
            }
        }
        return cnt;
    }
};

Time Complexity : O(n^2)

Space Complexity : O(1)

✅ Better Approach --> 

Time Complexity : 

Space Complexity : 

✅ Optimized Approach --> 

Time Complexity : 

Space Complexity : 

✅ Company Tags -->  