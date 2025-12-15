➡️ problemLinks --> https://www.geeksforgeeks.org/problems/aggressive-cows/1  &&  https://leetcode.com/problems/magnetic-force-between-two-balls/submissions/1856033641/

✅ Optimized Approach For GFG --> bool canWePlace(vector<int> &stalls, int cows, int dist){
    int count=1; // One cow placed ✔
    int last=stalls[0]; // Remember where it is placed
    
     // Loop through all stalls
        for (int i = 1; i < stalls.size(); i++) {
            // If the distance is at least d, we place a cow here.
            if (stalls[i] - last >= dist) {
                // Place the cow here
                count++;
                // Update last placed cow position
                last = stalls[i];
            }
            // If all cows are placed successfully
            if (count >= cows) return true;
        }
        // Return false if we could not place all cows
        return false;
}

class Solution {
  public:
    int aggressiveCows(vector<int> &stalls, int cows) {
        sort(stalls.begin(), stalls.end());
        int low = 1;
        int high = stalls.back() - stalls.front(); // or stalls[n-1] - stalls[0];
        int ans = 0;

        while (low <= high) {
            // int mid = low + (high - low) / 2;
            int mid = (low+high)/2;

            // If placing cows is possible with 'mid' distance
            if (canWePlace(stalls, cows, mid)) {
                ans = mid; // This distance works 👍
                low = mid + 1; // Try an even bigger distance
            }
            else {
                // Otherwise try smaller distance
                high = mid - 1;
            }
        }
        // Return the largest minimum distance
        return ans;
    }
};

// Time Complexity: O(NlogN) + O(N * log(max(stalls[])-min(stalls[]))), where N = size of the array, max(stalls[]) = maximum element in stalls[] array, min(stalls[]) = minimum element in stalls[] array.

// Space Complexity: O(1) as we are not using any extra space to solve this problem.

✅ Optimized Approach For leetcode -->  bool canPlace(vector<int>& position, int m, int d) {
    int count = 1;
    int last = position[0];

    for (int i = 1; i < position.size(); i++) {
        if (position[i] - last >= d) {
            count++;
            last = position[i];
        }
        if (count >= m) return true;
    }
    return false;
}

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

    int low = 1;
    int high = position.back() - position.front();
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlace(position, m, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
    }
};

✅ Company Tags -->  