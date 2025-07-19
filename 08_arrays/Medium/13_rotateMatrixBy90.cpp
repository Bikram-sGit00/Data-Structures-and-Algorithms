➡️ problemLinks --> https://www.geeksforgeeks.org/problems/rotate-by-90-degree0356/1  && https://leetcode.com/problems/rotate-image/description/

✅ Brute Force -->  The brute force approach involves creating a new matrix and copying the elements from the original matrix to the new matrix in the rotated position. This approach has a time complexity of O(N^2) and a space complexity of O(N^2).

vector < vector < int >> rotate(vector < vector < int >> & matrix) {
    int n = matrix.size();
    vector < vector < int >> rotated(n, vector < int > (n, 0));
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        rotated[j][n - i - 1] = matrix[i][j];
    }
    }
    return rotated;
}

✅ Optimized Approach -->  The better approach involves rotating the matrix in place by first transposing the matrix and then reversing each row. This approach has a time complexity of   O(N^2) and a space complexity of O(1).

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(); // Get the size of the matrix (n x n)

        // Step 1: Transpose the matrix
        // Transpose means converting rows into columns
        // We only need to swap elements above the diagonal to avoid double swapping
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                // Swap matrix[i][j] with matrix[j][i]
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        // This gives us the final rotated matrix (90 degrees clockwise)
        for (int i = 0; i < n; i++) {
            // Reverse the i-th row
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

✅ Company Tags --> Paytm Zoho Morgan Stanley Amazon Microsoft Samsung Snapdeal D-E-Shaw

