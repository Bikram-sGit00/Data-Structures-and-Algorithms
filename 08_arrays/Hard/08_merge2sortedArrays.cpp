➡️ problemLinks --> https://leetcode.com/problems/merge-sorted-array/ && https://www.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1

✅ Brute Force -->  The brute force approach involves creating a new array to hold the merged elements from both input arrays. We can then iterate through both arrays, comparing their elements and inserting the smaller ones into the new array so that they remain sorted . Finally, we copy any remaining elements from either array into the new array.

void merge(long long arr1[], long long arr2[], int n, int m) {

    //Declare a 3rd array and 2 pointers:
    long long arr3[n + m];
    int left = 0;
    int right = 0;

    int index = 0;

    //Insert the elements from the 2 arrays
    // into the 3rd array using left and right
    // pointers:

    while (left < n && right < m) {
        if (arr1[left] <= arr2[right]) {
            arr3[index] = arr1[left];
            left++, index++;
        }
        else {
            arr3[index] = arr2[right];
            right++, index++;
        }
    }

    // If right pointer reaches the end:
    while (left < n) {
        arr3[index++] = arr1[left++];
    }

    // If left pointer reaches the end:
    while (right < m) {
        arr3[index++] = arr2[right++];
    }

    // Fill back the elements from arr3[]
    // to arr1[] and arr2[]:
    for (int i = 0; i < n + m; i++) {
        if (i < n) arr1[i] = arr3[i];
        else arr2[i - n] = arr3[i];
    }
}

// Time Complexity: O(n + m) + O(n + m) where n and m are the sizes of the two input arrays. This is because we traverse both arrays once.
// Space Complexity: O(n + m) for the additional array used to store the merged elements.

✅ Optimized Approach 1 -->  The better approach involves using a two-pointer technique. We can maintain two pointers, one at the left array largest element (n-1) and one at smallest for another array and swaping and the corresponding pointer is incremented. This approach avoids the need for extra space and is more efficient.
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m - 1;
        int right = 0;
        while (left >= 0 && right < n) {
            if (nums1[left] > nums2[right]) {
                swap(nums1[left], nums2[right]);
                left--;
                right++;
            } else {
                break;
            }
        }
        sort(nums1.begin(), nums1.begin() + m); // sort only valid part
        sort(nums2.begin(), nums2.end());
        for (int k = 0; k < n; ++k) {
            nums1[m + k] = nums2[k];
        }
    }
};
// Time Complexity: O( min(n,m) + nlog n + m log m) where n and m are the sizes of the two input arrays. This is because we sort both arrays after merging.
// Space Complexity: O(1) since we are not using any additional space for merging.

✅ Optimized Approach 2 -->  The optimized approach involves merging the arrays in place. We can start from the end of both arrays and compare their elements, inserting the larger one into the correct position in the merged array. This approach also avoids the need for extra space and is the most efficient.

✅ Company Tags -->  