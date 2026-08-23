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

✅ Optimized Brute Force --> class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt  = 0;
        for(int i = 0; i < n; i++){
            vector<int> hash(3,0);
            for(int j = i; j < n; j++){
                hash[s[j] - 'a'] = 1;
                if(hash[0]+hash[1]+hash[2] == 3){  
                    cnt += n - j; // Explanation: ↓
                    break;
                }
            }
        }
        return cnt;
    }
};

// s = "abcabc"
//             j
//             ↓
// index:  0 1 2 3 4 5
//         a b c a b c

// when j = 2, we got valid substring "abc" and after that every thing will be valid we know 
// abca
// abcab            // these all are valid, and to know how many just do n - j, for now j = 2 and n = 6 => 4, "abc" + other 3 on the left 
// abcabc

Time Complexity : just a suttle improvement over brute force, still O(n^2) in worst case  

Space Complexity : O(1)

✅ Optimized Approach --> 

Time Complexity : 

Space Complexity : 

✅ Company Tags -->  