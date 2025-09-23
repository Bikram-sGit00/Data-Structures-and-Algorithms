➡️ problemLinks --> https://www.geeksforgeeks.org/problems/implement-lower-bound/1  && https://leetcode.com/problems/search-insert-position/

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
            if (arr[mid] > target) <--
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

✅ Search Insert Position --> class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = n;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] >= target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

// Time Complexity --> O(log base2^N) or O(log2(N))
// Space Complexity --> O(1)

✅ Floor --> largest element smaller than or equal to x

int findFloor(int arr[], int n, int x) {
	int low = 0, high = n - 1;
	int ans = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		// maybe an answer
		if (arr[mid] <= x) {
			ans = arr[mid];  // or ans = mid; if index is needed
			//look for smaller index on the left
			low = mid + 1;
		}
		else {
			high = mid - 1; // look on the right
		}
	}
	return ans;
}


✅ Ceil --> smallest element greater than or equal to x
int findCeil(int arr[], int n, int x) {
	int low = 0, high = n - 1;
	int ans = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		// maybe an answer
		if (arr[mid] >= x) {
			ans = arr[mid];
			//look for smaller index on the left
			high = mid - 1;
		}
		else {
			low = mid + 1; // look on the right
		}
	}
	return ans;
}

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

