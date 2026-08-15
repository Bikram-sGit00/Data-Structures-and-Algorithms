➡️ problemLinks --> https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

✅ Brute Force -->  class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();

        vector<int> knows(n, 0);       // knows[i] = number of people i knows
        vector<int> knownBy(n, 0);     // knownBy[i] = number of people who know i

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 1) {
                    knows[i]++;       // i knows j
                    knownBy[j]++;     // j is known by i
                }
            }
        }

        for(int i = 0; i < n; i++) {
            if(knows[i] == 0 && knownBy[i] == n - 1)
                return i; // i knows nobody and everybody knows i
        }

        return -1; // no celebrity exists
    }
};

Time Complexity : O(n^2) --> for traversing the matrix
Space Complexity : O(2n) --> for storing the knows and knownBy arrays



✅ Better Approach -->  class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();

        for(int i = 0; i < n; i++) { // try every person as a possible celebrity
            bool celebrity = true;

            for(int j = 0; j < n; j++) { // check this person against everyone
                if(i == j) continue;                   // skip checking the person against themselves

                if(mat[i][j] == 1 || mat[j][i] == 0) { // celebrity knows someone OR someone doesn't know them
                    celebrity = false;
                    break; // no need to check further
                }
            }

            if(celebrity) return i; // all conditions passed → found celebrity
        }

        return -1; // no celebrity exists
    }
};

Time Complexity : O(n^2)
Space Complexity : O(1)



✅ Optimized Approach --> class Solution {
	public:
	int celebrity(vector<vector<int>> & mat) {
		// code here
		int n = mat.size(); // number of people
		int top = 0; // left candidate
		int down = n - 1; // right candidate
		
		while (top<down) {
			if (mat[top][down] == 1) top++;       // top knows down → top cannot be celebrity
			else if (mat[down][top] == 1) down--; // down knows top → down cannot be celebrity
			else top ++, down --;                 // both can't be celebrity → eliminate both
		}

		if(top > down) return -1;         // no candidate remains

		else{
		    for(int i=0;i<n;i++){
		        if(i == top) continue;    // skip checking the candidate against itself

		        if(mat[top][i]== 0 && mat[i][top] == 1)
		            continue;             // top knows nobody and everybody knows top
		        else
		            return -1;            // candidate fails celebrity condition
		    }
		}
        return top; // candidate is celebrity
	}
};

Time Complexity : O(2N)

Space Complexity : O(1)

✅ Company Tags -->  Zoho Flipkart Amazon Microsoft Google Fab.com One97 UnitedHealthGroup NPCI