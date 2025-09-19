➡️ problemLinks --> https://www.geeksforgeeks.org/problems/implement-lower-bound/1

✅ Lower Bound --> 
- The lower bound of a sorted array is the index of the first element that is not less than a given value.
- To find the lower bound, we can use binary search.
- If the target value is found, we continue searching in the left half to find the first occurrence.
- If the target value is not found, we return the index where it can be inserted.

class Solution{
public:
    int lowerBound(vector<int> &arr, int target){
        int n = arr.size();
        int low = 0, high = n - 1, ans = n;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] >= target)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};


// Time Complexity --> O(log base2^N) or O(log2(N))
// Space Complexity --> O(1)

✅ Upper Bound -->
- The upper bound of a sorted array is the index of the first element that is greater than a given value.
- To find the upper bound, we can use binary search.
- If the target value is found, we continue searching in the right half to find the first element greater than the target

class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0, high = n - 1, ans = n;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] > target)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};

// Time Complexity --> O(log base2^N) or O(log2(N))
// Space Complexity --> O(1)