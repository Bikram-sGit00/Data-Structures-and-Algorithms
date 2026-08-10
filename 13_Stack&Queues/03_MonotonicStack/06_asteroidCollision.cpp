➡️ problemLinks --> https://leetcode.com/problems/asteroid-collision/submissions/2101582301/

✅ Optimized Approach --> class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> st; // Stack stores only the asteroids that are still alive.

        for (int i = 0; i < n; i++) {

            // Right-moving asteroid cannot collide with anything behind it yet.
            if (asteroids[i] > 0) {
                st.push_back(asteroids[i]);
            } 
            else {

                // Current asteroid is moving LEFT.
                // Collision is possible only with a RIGHT-moving asteroid at the top.
                // If current is bigger, destroy the top and keep checking backwards.
                while (!st.empty() && st.back() > 0 && abs(asteroids[i]) > st.back()) 
                    st.pop_back();

                // Equal sizes → both explode.
                // Pop the stack asteroid; current asteroid is simply NOT pushed.
                if (!st.empty() && abs(asteroids[i]) == st.back()) 
                    st.pop_back();

                // No collision possible → current asteroid survives.
                // Either stack is empty or top is already moving LEFT.
                else if (st.empty() || st.back() < 0) 
                    st.push_back(asteroids[i]);
            }
        }

        return st;
    }
};

Time Complexity : O(2n)
Space Complexity : O(n)

✅ Company Tags -->  