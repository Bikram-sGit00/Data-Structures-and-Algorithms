➡️ problemLinks --> https://leetcode.com/problems/median-of-two-sorted-arrays/  &&  https://www.geeksforgeeks.org/problems/median-of-2-sorted-arrays-of-different-sizes/1

✅ Brute Force --> class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Create a merged vector to store sorted elements
        vector<int> merged;
        
        // Initialize two pointers
        int i = 0, j = 0;
        
        // Merge both arrays in sorted order
        while (i < nums1.size() && j < nums2.size()) {
            // Push the smaller element into merged
            if (nums1[i] < nums2[j]) {
                merged.push_back(nums1[i]);
                i++;
            } else {
                merged.push_back(nums2[j]);
                j++;
            }
        }
        
        // Add remaining elements from nums1
        while (i < nums1.size()) {
            merged.push_back(nums1[i]);
            i++;
        }

        // Add remaining elements from nums2
        while (j < nums2.size()) {
            merged.push_back(nums2[j]);
            j++;
        }

        // Find median based on size
        int n = merged.size();
        if (n % 2 == 1)
            return merged[n / 2];
        else
            return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
    }
};

// Time Complexity: O(m + n)
// Space Complexity: O(m + n)

✅ Better Approach --> 
// Function to find the median of two sorted arrays
double median(vector<int>& a, vector<int>& b) {

    // Get sizes of both arrays
    int n1 = a.size(), n2 = b.size();

    // Calculate total size
    int n = n1 + n2;

    // Calculate the middle indices
    int ind2 = n / 2;
    int ind1 = ind2 - 1;

    // Initialize pointers and counters
    int cnt = 0, i = 0, j = 0;
    int ind1el = -1, ind2el = -1;

    // Traverse both arrays like merge step of merge sort
    while (i < n1 && j < n2) {

        // Check which element is smaller and pick it
        if (a[i] < b[j]) {
            if (cnt == ind1) ind1el = a[i];
            if (cnt == ind2) ind2el = a[i];
            i++;
        } else {
            if (cnt == ind1) ind1el = b[j];
            if (cnt == ind2) ind2el = b[j];
            j++;
        }
        cnt++;
    }

    // Copy remaining elements from first array if any
    while (i < n1) {
        if (cnt == ind1) ind1el = a[i];
        if (cnt == ind2) ind2el = a[i];
        cnt++;
        i++;
    }

    // Copy remaining elements from second array if any
    while (j < n2) {
        if (cnt == ind1) ind1el = b[j];
        if (cnt == ind2) ind2el = b[j];
        cnt++;
        j++;
    }

    // Return median depending on even or odd size
    if (n % 2 == 1) return (double)ind2el;
    return (ind1el + ind2el) / 2.0;
}

// Time Complexity: O(m + n)
// Space Complexity: O(1)

✅ Optimized Approach --> 

✅ Company Tags -->  