➡️ problemLinks-- > https : // leetcode.com/problems/maximum-subarray/

✅ Brute Force-- > int maxSubarraySum(int arr[], int n)
{
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            // subarray = arr[i.....j]
            int sum = 0;

            // add all the elements of subarray:
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }

            maxi = max(maxi, sum);
        }
    }

    return maxi;
}

//Time Complexity: O(n^3)  &&  Space Complexity: O(1);

✅ Better Approach-- > int maxSubarraySum(int arr[], int n)
{
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            // current subarray = arr[i.....j]

            // add the current element arr[j]
            //  to the sum i.e. sum of arr[i...j-1]
            sum += arr[j];

            maxi = max(maxi, sum); // getting the maximum
        }
    }

    return maxi;
}

//Time Complexity: O(n^2)  &&  Space Complexity: O(1);

✅ mostOptimal-- > class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0;
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum > maxi)
            {
                maxi = sum;
            }
            if (sum < 0)
            {
                sum = 0;
            }
        }
        if (sum < 0)
        {
            return maxi = 0; // if all elements are negative, return 0 , which means no subarray
        }
        return maxi;
    }
};

//Time Complexity: O(n)  &&  Space Complexity: O(1);

Company Tags --> Amazon Microsoft Intuit