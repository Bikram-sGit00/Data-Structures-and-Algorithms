➡️ problemLinks --> https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

✅ Optimized Approach --> int sumOfDevisors(vector<int>& nums, int div) {
    int sum = 0;
    for (auto X : nums) {
        sum += (X + div - 1) / div;
    }
    return sum;
}

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        while (low <= high) {
            int mid = (low + high) / 2;
            if (sumOfDevisors(nums, mid) <= threshold) {

                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

// Time Complexity --> O(N * logM) where N is the number of elements in the array and M is the maximum element in the array.
// Space Complexity --> O(1)

✅ Company Tags -->  