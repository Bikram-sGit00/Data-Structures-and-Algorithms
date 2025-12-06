➡️ problemLinks --> https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

✅ Optimized Approach --> int knowDays(vector<int>& weights, int capacity) {
    int day = 1, load = 0;
    for (int i = 0; i < weights.size(); i++) {
        if (weights[i] + load > capacity) {
            day += 1;
            load = weights[i];
        } else {
            load += weights[i];
        }
    }
    return day;
}

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0); // sum of all
        while (low <= high) {
            int mid = (low + high) / 2;
            int reqDays = knowDays(weights, mid);
            if (reqDays <= days) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

// Time Complexity --> O(N log(sum of weights))
// Space Complexity --> O(1)

✅ Company Tags -->  Amazon D-E-Shaw