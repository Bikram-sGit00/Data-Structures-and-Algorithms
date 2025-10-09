➡️ problemLinks --> https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/ && https://www.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1

✅ Brute Force -->  Iterate through the array and find the first and last occurrence of the target element.

✅ Optimized Approach --> int lowerBound(vector<int>& arr, int target) {
    int n = arr.size();
    int low = 0, high = n - 1, ans = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] >= target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int upperBound(vector<int>& arr, int target) {
    int n = arr.size();
    int low = 0, high = n - 1, ans = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] > target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int x) {
        int n = arr.size();
        int lb = lowerBound(arr, x);
        if (lb == n || arr[lb] != x)  // checking if element is not in the array...
            return {-1, -1};
        return {lb, upperBound(arr, x) - 1};
    }
};


✅ Company Tags -->  Amazon





✅ Find First & Last element --> class Solution {
public:
    int findFirst(vector<int>& arr, int x) {
        int low = 0, high = arr.size() - 1;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == x) {
                ans = mid;
                high = mid - 1; // keep searching left
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    int findLast(vector<int>& arr, int x) {
        int low = 0, high = arr.size() - 1;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == x) {
                ans = mid;
                low = mid + 1; // keep searching right
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& arr, int x) {
        int first = findFirst(arr, x);
        int last = findLast(arr, x);
        return {first, last};
    }
};



✅ Count occurrences of a number in a sorted array with duplicates -->