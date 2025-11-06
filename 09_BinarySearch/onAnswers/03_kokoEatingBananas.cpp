➡️ problemLinks --> https://leetcode.com/problems/koko-eating-bananas/description/  & https://www.geeksforgeeks.org/problems/koko-eating-bananas/1

✅ Optimized Approach --> int findmax(const vector<int>& piles) { // finding the max element into the array
    int maxi = INT_MIN;
    for (int x : piles)
        maxi = max(maxi, x);
    return maxi;
}

long long calculateTotalHours(const vector<int>& piles, int perHour) {// counting time need for each block of piles
    long long totalTime = 0;
    for (int x : piles) {
        // ceil(x / perHour) without floating point
        totalTime += (x + perHour - 1) / perHour; // This line is a trick to perform ceiling division (integer division rounded up), without using ceil() or floating-point math.
    }
    return totalTime;
}

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int deadline) {
        int low = 1; 
        int high = findmax(piles);
        while (low <= high) {
            int mid = low + (high - low) / 2; 
            long long timeTaken = calculateTotalHours(piles, mid);
            if (timeTaken <= deadline) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

// Time Complexity: O(N * log M) where N is the number of piles and M is the maximum number of bananas in a pile.
// Space Complexity: O(1) as we are using constant extra space.

✅ Company Tags -->  Bloomberg Amazon Microsoft Walmart Adobe Arcesium Uber