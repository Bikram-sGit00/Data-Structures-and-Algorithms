// https://www.geeksforgeeks.org/problems/key-pair5616/1

// Brute force approach
string twoSum(int n, vector<int> &arr, int target)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
                return "YES";
        }
    }
    return "NO";
}
Output: This is the answer for variant 1: YES

Time Complexity: O(N2), where N = size of the array.
Reason: There are two loops(i.e. nested) each running for approximately N times.

Space Complexity: O(1) as we are not using any extra space.

//Better approach

class Solution
{
public:
    bool twoSum(vector<int> &arr, int target)
    {
        map<int, int> mpp;
        for (int i = 0; i < arr.size(); i++)
        {
            int firstEle = arr[i];
            int moreNeed = target - firstEle;
            if (mpp.find(moreNeed) != mpp.end())
            {
                return true;
            }
            mpp[firstEle] = i;
        }
        return false;
    }
};
Output: This is the answer for variant 1: YES

Time Complexity: O(N), where N = size of the array.
Reason: The loop runs N times in the worst case and searching in a hashmap takes O(1) generally. So the time complexity is O(N).

Note: In the worst case(which rarely happens), the unordered_map takes O(N) to find an element. In that case, the time complexity will be O(N2). If we use map instead of unordered_map, the time complexity will be O(N* logN) as the map data structure takes logN time to find an element.

Space Complexity: O(N) as we use the map data structure.

Note: We have optimized this problem enough. But if in the interview, we are not allowed to use the map data structure, then we should move on to the following approach i.e. two pointer approach. This approach will have the same time complexity as the better approach.

//if they ask you to return indexs : https://leetcode.com/problems/two-sum/
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            map<int, int> mpp;
            for (int i = 0; i < nums.size(); i++) {
                int firstEle = nums[i];
                int moreNeed = target - firstEle;
                if (mpp.find(moreNeed) != mpp.end()) {
                    return {mpp[moreNeed], i};
                }
                mpp[firstEle] = i;
            }
            return {-1, -1};
        }
};

//optimal approach of sorted array : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
class Solution {
    public:
        vector<int> twoSum(vector<int>& arr, int target) {
            int n = arr.size();
            int left = 0;
            int right = n - 1;
            while (left < right) {
                int sum = arr[left] + arr[right];
                if (sum == target) {
                    return {left + 1, right + 1}; // index is being increment by 1 as they want 1based indexing...
                                                  
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
            return {-1, -1};
        }
};

Company Tags--> Zoho Flipkart Morgan Stanley Accolite Amazon Microsoft FactSetHike Adobe Google Wipro SAP LabsCarWale;
