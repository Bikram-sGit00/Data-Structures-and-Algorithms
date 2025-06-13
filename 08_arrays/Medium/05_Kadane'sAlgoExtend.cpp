➡️ problemLinks --> https://www.geeksforgeeks.org/problems/maximum-sub-array5443/1 ;

✅ mostOptimal --> class Solution
{
public:
    vector<int> findSubarray(vector<int> &nums)
    {
        // Initialize the max sum as -1 (in case no non-negative numbers are found)
        int maxSum = -1;
        int currentSum = 0;

        // To track the start and end indices of the best (maximum sum) subarray..we will store the best start in order to compare with the new better subarray...
        int bestStart = 0, bestEnd = -1;  // bestEnd will be -1 initially to indicate no valid subarray found yet.

        // To track the start index of the current subarray we are checking
        int currentStart = 0;

        // Loop through each element in the array
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= 0)
            {
                // If number is non-negative, add to the current sum
                currentSum += nums[i];

                // If this is the best sum so far OR
                // If it's equal to max sum but the subarray is longer
                if (currentSum > maxSum || 
                   (currentSum == maxSum && (i - currentStart > bestEnd - bestStart))) //check if the current subarray is longer than the best found so far...
                {
                    maxSum = currentSum;
                    bestStart = currentStart;
                    bestEnd = i;
                }
            }
            else
            {
                // If number is negative, reset current subarray
                currentSum = 0;
                currentStart = i + 1; // Start fresh from the next element
            }
        }

        // If no non-negative subarray was found, return {-1}
        if (maxSum == -1)
            return {-1};

        // Return the subarray from bestStart to bestEnd (inclusive)
        return vector<int>(nums.begin() + bestStart, nums.begin() + bestEnd + 1);
    }
};


//Time Complexity: O(n)  &&  Space Complexity: O(1);

Company Tags --> Amazon Microsoft Intuit Zoho Flipkart Morgan Stanley Accolite Microsoft Samsung Snapdeal 24*7Innovation Labs Citrix D-E-Shaw FactSet Hike Housing.com MetLife Ola Cabs Oracle Payu Teradata Visa Walmart Adobe Google Arcesium

