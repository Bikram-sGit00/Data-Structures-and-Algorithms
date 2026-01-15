➡️ problemLinks --> https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

                                                            Extend of "12_medianOfSortedArray.cpp" problem...
✅ Optimized Approach --> class Solution {
  public:
    int kthElement(vector<int> &nums1, vector<int> &nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int total = n1 + n2;
        if (n1 > n2)
            return kthElement(
                nums2, nums1 ,k); // as we always want nums1 to be small
        int low = max(0,k-n2);
        int high = min(k,n1);
        int left = k;
        while (low <= high) {
            int mid1 = (low + high) / 2;
            int mid2 = left - mid1;
            int l1 = INT_MIN, l2 = INT_MIN; // if they are not there
            int r1 = INT_MAX, r2 = INT_MAX; // if they are not there
            if (mid1 < n1)
                r1 = nums1[mid1];
            if (mid2 < n2)
                r2 = nums2[mid2];
            if (mid1 - 1 >= 0)
                l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = nums2[mid2 - 1];
            if (l1 <= r2 && l2 <= r1) {
                    return max(l1, l2);
            } else if (l1 > r2)
                high = mid1 - 1;
            else
                low = mid1 + 1;
        }
        return 0;
    }
};

// Time Complexity: O(log(min(M, N))), where M and N are the sizes of the two given arrays. As binary search is being applied on the range [max(0, k - N2), min(k, N1)], the range length <= min(M, N).
// Space Complexity: O(1), as no additional space is used.

✅ Company Tags -->  Flipkart Microsoft