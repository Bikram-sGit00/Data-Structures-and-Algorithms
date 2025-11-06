➡️ problemLinks --> https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/ && 

✅ Optimized Approach --> bool possible(vector<int>& arr, int day, int m, int k) {
    int cnt = 0;
    int noOfBqts = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] <= day) {
            cnt++;
        } else {
            noOfBqts += (cnt / k); // from the streak before this, make as many k-sized bouquets as possible
            cnt = 0; // reset the counter for new series
        }
    }
    noOfBqts += (cnt / k);
    return noOfBqts >= m;
}

class Solution {
public:
    int minDays(vector<int>& arr, int m, int k) {
    long long val = m * 1ll * k * 1ll; // total flowers needed = m*k (done in long long to avoid overflow)
    int n = arr.size();                // number of flowers
    if (val > n) return -1;            // impossible if garden has fewer flowers than needed

    // find minimum and maximum bloom day in arr (search space for answer)
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        mini = min(mini, arr[i]);      // smallest day any flower blooms
        maxi = max(maxi, arr[i]);      // largest day any flower blooms
    }

    // apply binary search over days [mini .. maxi]
    int low = mini, high = maxi;
    while (low <= high) {
        int mid = (low + high) / 2;    // try this day as a candidate
        if (possible(arr, mid, m, k)) { // can we make m bouquets by 'mid'?
            high = mid - 1;            // yes → try to find an even earlier day
        }
        else low = mid + 1;            // no → need more time, move right
    }
    return low;       
    }
};

✅ Company Tags -->  Bloomberg Amazon Microsoft Google Flipkart