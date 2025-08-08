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

✅ Optimized Approach 2 --> "Shell Sort" algorithm can be used to merge two sorted arrays in O(n + m) time complexity without using extra space. The idea is to use a gap-based approach, where we compare elements at a certain gap and swap them if they are out of order. This continues until the gap is reduced to 0
class Solution {
private:
    void isGreater(vector<int>& nums1, int indx1, vector<int>& nums2, int indx2) {
        if (nums1[indx1] > nums2[indx2]) {
            swap(nums1[indx1], nums2[indx2]);
        }
    }
public:
    void mergeArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if (n == 0) return;
        
        int len = (n + m);
        int gap = (len / 2) + (len % 2);

        while (gap > 0) {
            int left = 0;
            int right = left + gap;
            while (right < len) {
                if (left < n && right >= n) {
                    isGreater(nums1, left, nums2, right - n);
                } else if (left >= n) {
                    isGreater(nums2, left - n, nums2, right - n);
                } else {
                    isGreater(nums1, left, nums1, right);
                }
                left++;
                right++;
            }
            if (gap == 1) break;
            gap = (gap / 2) + (gap % 2);
        }
    }
};
// this code will not work in leetcode 

// Time Complexity: O((n+m)*log(n+m)), where n and m are the sizes of the given arrays.
// Reason: The gap is ranging from n+m to 1 and every time the gap gets divided by 2. So, the time complexity of the outer loop will be O(log(n+m)). Now, for each value of the gap, the inner loop can at most run for (n+m) times. So, the time complexity of the inner loop will be O(n+m). So, the overall time complexity will be O((n+m)*log(n+m)).

// Space Complexity: O(1) as we are not using any extra space.
✅ Company Tags -->  Zoho Microsoft Snapdeal Goldman Sachs Adobe Linkedin Amdocs Brocade Juniper Networks Quikr Synopsys