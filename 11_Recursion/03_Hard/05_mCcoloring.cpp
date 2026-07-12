➡️ problemLinks --> https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

✅ Optimized Approach --> class Solution {
public:

    // isSafe(node, col)
    // Check if 'col' can be assigned to 'node'.
    // Scan every edge.
    // If any adjacent node already has the same color,
    // return false. Otherwise return true.
    bool isSafe(int node, vector<int> &color, vector<vector<int>> &edges, int v, int col) {

        // Visit every edge
        for (auto &edge : edges) {

            // Two endpoints of the current edge
            int u = edge[0];
            int w = edge[1];

            // If current node is u,
            // check neighbour w
            if (u == node && color[w] == col)
                return false;

            // If current node is w,
            // check neighbour u
            if (w == node && color[u] == col)
                return false;
        }

        return true;
    }

    // solve(node)
    // Can I color this node AND all remaining nodes?
    bool solve(int node, vector<int> &color, vector<vector<int>> &edges, int v, int m) {

        // Base Case:
        // All vertices are colored
        if (node == v)
            return true;

        // Try every possible color
        for (int col = 1; col <= m; col++) {

            // Can this color be assigned?
            if (isSafe(node, color, edges, v, col)) {

                // Choose
                color[node] = col;

                // Explore:
                // Can all remaining nodes be colored?
                if (solve(node + 1, color, edges, v, m))
                    return true;

                // Undo (Backtracking)
                color[node] = 0;
            }
        }

        // No valid coloring found
        return false;
    }

    bool graphColoring(int v, vector<vector<int>> &edges, int m) {

        // color[i] = color assigned to vertex i
        vector<int> color(v, 0);

        // Start coloring from node 0
        return solve(0, color, edges, v, m);
    }
};

// Time Complexity : O(m^V) where V is the number of vertices and m is the number of colors. In the worst case, we may have to try all m colors for each of the V vertices.
// Space Complexity : O(V) + O(V) = O(V) where O(V) is for the color array and O(V) is for the recursion stack.

✅ Company Tags -->  Amazon 