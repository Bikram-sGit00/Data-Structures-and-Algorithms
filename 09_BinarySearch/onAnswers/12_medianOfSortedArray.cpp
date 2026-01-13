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

✅ Optimized Approach --> 

✅ Company Tags -->  