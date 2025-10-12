➡️ problemLinks --> https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/  &&  https://www.geeksforgeeks.org/problems/minimum-number-in-a-sorted-rotated-array-1587115620/1

✅ Optimized Approach --> class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int ans = INT_MAX;
        while (low <= high) {
            int mid = (low + high) / 2;
            if(arr[low]<=arr[high]){ // check case if whole array is sorted
              ans=min(ans,arr[low]);
              break;
            }
            if (arr[low]<=arr[mid]){
              ans=min(ans,arr[low]);
              low=mid+1;
            }
            else{
              ans=min(ans,arr[mid]);
              high=mid-1;
            }
        }
        return ans;
    }
};

// Time Complexity: O(log base2 N) in average case and O(N) in worst case
// Space Complexity: O(1)

➡️ problem --> Find out how many times has an array been rotated (similar to this problem) 

✅ Optimized Approach --> class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int ans = INT_MAX;
        int index =-1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if(arr[low]<=arr[high]){ // check case if whole array is sorted
              if(arr[low]<ans){
                  ans=arr[low];
                  index=low;
              }
              break;
            }
            if (arr[low]<=arr[mid]){
              if(arr[low]<ans){
                ans=arr[low];
                index=low;
              }
              low=mid+1;
            }
            else{
              if(arr[mid]<ans){
                  ans=arr[mid];
                  index=mid;
              }
              high=mid-1;
            }
        }
        return index;
    }
};

// Time Complexity: O(log base2 N) in average case and O(N) in worst case
// Space Complexity: O(1)


✅ Company Tags -->  Flipkart Amazon ABCO