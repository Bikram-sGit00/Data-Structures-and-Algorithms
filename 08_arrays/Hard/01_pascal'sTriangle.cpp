➡️ problemLinks --> https://leetcode.com/problems/pascals-triangle/ && https://www.geeksforgeeks.org/problems/pascal-triangle0652/1

✅ Optimized Approach --> For Leetcode 
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result; // This will hold all the rows of Pascal's Triangle

        // Loop through each row from 0 to numRows - 1
        for (int row = 0; row < numRows; row++) {
            vector<int> ansRow;      // This will store the current row
            long long ans = 1;       // First number in every row is always 1
            ansRow.push_back(1);     // Push the first 1 to the row

            // Now calculate the rest of the numbers in this row
            for (int col = 1; col <= row; col++) {
                // Formula to calculate binomial coefficient: C(n, k)
                ans = ans * (row - col + 1); // Multiply with (n - k + 1)
                ans = ans / col;             // Divide by k
                ansRow.push_back(ans);       // Add the number to the current row
            }

            result.push_back(ansRow); // Add the completed row to the triangle
        }

        return result; // Return the full Pascal's Triangle
    }
};

// Time Complexity: O(n^2) where n is the number of rows
// Space Complexity: O(n^2) for storing the triangle

✅ Optimized Approach --> For GeeksforGeeks
class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        long long ans = 1;
        vector<int> result;
        result.push_back(1);
        for(int i = 1; i < n; i++){
            ans = ans*(n-i);
            ans = ans / i;
            result.push_back(ans);
        }
        return result;
    }
};

// Time Complexity: O(n) for generating the nth row
// Space Complexity: O(n) for storing the row

✅ Company Tags -->  Amazon Microsoft Adobe