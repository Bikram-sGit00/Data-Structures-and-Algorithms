➡️ problemLinks --> https://leetcode.com/problems/single-element-in-a-sorted-array/  &&  https://www.geeksforgeeks.org/problems/find-the-element-that-appears-once-in-sorted-array0624/1

✅ Brute Force 1 -->  int singleNonDuplicate(vector<int>& arr) {
    int n = arr.size(); //size of the array.
    if (n == 1) return arr[0];

    for (int i = 0; i < n; i++) {

        //Check for first index:
        if (i == 0) {
            if (arr[i] != arr[i + 1])
                return arr[i];
        }
        //Check for last index:
        else if (i == n - 1) {
            if (arr[i] != arr[i - 1])
                return arr[i];
        }
        else {
            if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1])
                return arr[i];
        }
    }

    // dummy return statement:
    return -1;
}

// Time Complexity: O(N)
// Space Complexity: O(1)

✅ Brute Force 2 --> int singleNonDuplicate(vector<int>& arr) {
    int n = arr.size(); //size of the array.
    int ans = 0;
    // XOR all the elements:
    for (int i = 0; i < n; i++) {
        ans = ans ^ arr[i];
    }
    return ans;
}

// Time Complexity: O(N)
// Space Complexity: O(1)

✅ Optimized Approach --> class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 1, high = n - 2;
        if (n == 1)
            return nums[0];
        if (nums[0] != nums[1])
            return nums[0]; // if first element is answer
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1]; // if last element is answer
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
                return nums[mid];
            // We are in left
            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) ||
                (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
                low = mid + 1; // eleminate left half
            } else {
                high = mid - 1;
            }
        }
        return -1; // dummy statement
    }
};

✅ Company Tags -->  Amazon D-E-Shaw Ola Cabs