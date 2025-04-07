// https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=longest-sub-array-with-sum-k
// Brute Force Approach
//  Time Complexity: O(n^3)
//  Space Complexity: O(1)
int getLongestSubarray(vector<int> &a, long long k)
{
    int n = a.size(); // size of the array.

    int len = 0;
    for (int i = 0; i < n; i++)
    { // starting index
        for (int j = i; j < n; j++)
        {                    // ending index
            s += a[j];       // OR , O(n^2) & O(1) space complexity;
            long long s = 0; // add all the elements of subarray = a[i...j]:
            for (int K = i; K <= j; K++)
            {
                s += a[K];
            }

            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}

// Better Approach
//  Time Complexity: O(n * logn)
//  Space Complexity: O(n)

class Solution
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        map<int, int> sumMap;
        int sum = 0;
        int maxLen = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i]; // adding the elements of the array;
            if (sum == k)
            {
                maxLen = max(maxLen, i + 1); // if the sum is equal to k then ww will take the length of the subarray from 0 to i;
            }
            int rem = sum - k;
            if (sumMap.find(rem) != sumMap.end())
            {                              // checking if there is a rem element or not;
                int len = i - sumMap[rem]; // getting the length of the higher length subarray;
                maxLen = max(maxLen, len);
            }
            if (sumMap.find(sum) == sumMap.end()) // if the sum is not present in the map then we will insert it in the map;
            {
                sumMap[sum] = i; // inserting the sum and the index in the map;
            }
        }
        return maxLen;
    }
};

//optimal approach for positive & zero based arr[]
//  Time Complexity: O(2n)
//  Space Complexity: O(1)

int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.

    int left = 0, right = 0; // 2 pointers
    long long sum = a[0]; // sum as first element of the array
    int maxLen = 0;
    while (right < n) { // iterate until right pointer reaches the end of the array
        // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
        while (left <= right && sum > k) { //if sum>k remove the or subtract the left guy
            sum -= a[left];//<--
            left++;//move forward
        }

        // if sum = k, update the maxLen i.e. answer:
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1); //right-left+1 cause we are using 0 based indexing
        }

        // Move forward thw right pointer:
        right++;
        if (right < n) sum += a[right];
    }

    return maxLen;
}
