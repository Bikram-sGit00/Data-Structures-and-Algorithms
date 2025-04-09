// https://leetcode.com/problems/sort-colors/
Brute force --> is we use any sorting algorithm
Time complexity --> O(nlogn)
space complexity --> O(n)

Better Approach --> we declare 3 variables & overwrite the given arr[]
Time Complexity: O(N) + O(N), where N = size of the array. First O(N) for counting the number of 0's, 1's, 2's, and second O(N) for placing them correctly in the original array.
Space Complexity: O(1) as we are not using any extra space.

void sortArray(vector<int>& arr, int n) {

    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) cnt0++;
        else if (arr[i] == 1) cnt1++;
        else cnt2++;
    }

    //Replace the places in the original array:
    for (int i = 0; i < cnt0; i++) arr[i] = 0; // replacing 0's

    for (int i = cnt0; i < cnt0 + cnt1; i++) arr[i] = 1; // replacing 1's

    for (int i = cnt0 + cnt1; i < n; i++) arr[i] = 2; // replacing 2's

}

Optimized Approach --> Dutch National Flag Algorithm
Time complexity --> O(n) //cause we doing n times iteration do sort n elements
space complexity --> O(1)
class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int low = 0;
            int mid = 0;
            int high = nums.size() - 1;
            while (mid <= high) {
                if (nums[mid] == 0) {
                    swap(nums[low], nums[mid]);
                    low++;
                    mid++;
                } else if (nums[mid] == 1)
                    mid++;
                else {
                    swap(nums[mid], nums[high]);
                    high--;
                }
            }
        }
};