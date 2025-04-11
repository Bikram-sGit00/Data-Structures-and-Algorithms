https://leetcode.com/problems/majority-element/

Brute force --> int majorityElement(vector<int> v) {
    //size of the given array:
    int n = v.size();

    for (int i = 0; i < n; i++) {
        //selected element is v[i]
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            // counting the frequency of v[i]
            if (v[j] == v[i]) {
                cnt++;
            }
        }

        // check if frequency is greater than n/2:
        if (cnt > (n / 2))
            return v[i];
    }

    return -1;
}
Time Complexity --> O(N2), where N = size of the given array. Reason: For every element of the array the inner loop runs for N times. And there are N elements in the array. So, the total time complexity is O(N2). Space Complexity: O(1) as we use no extra space.

Better Approach --> Hashing
class Solution {
    public:
      int majorityElement(vector<int>& arr) {
          map<int,int>mpp;
          for(int i=0;i<arr.size();i++){
              mpp[arr[i]]++;
          }
          for(auto it: mpp){
              if(it.second>(arr.size()/2)){
                  return it.first;
              }
          }
          return -1;
      }
};
Time Complexity --> O(N*logN) + O(N), where N = size of the given array.
Reason: We are using a map data structure. Insertion in the map takes logN time. And we are doing it for N elements. So, it results in the first term O(N*logN). The second O(N) is for checking which element occurs more than floor(N/2) times. If we use unordered_map instead, the first term will be O(N) for the best and average case and for the worst case, it will be O(N2).
Space Complexity --> O(N) as we are using a map data structure

Optimal Approach -->  Moore's Voting Algorithm:
class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int ele;
            int cnt = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (cnt == 0) {
                    cnt = 1;
                    ele = nums[i];
                } else if (nums[i] == ele) {
                    cnt++;
                } else {
                    cnt--;
                }
            }
            //checking if the element is >n/2 or not -->
            int checkCounter = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if(nums[i]==) checkCounter++;
            }
            if (checkCounter >= nums.size()/2)
            {
                return ele;
            }
            return -1;
        }
};
Time Complexity --> O(N), where N = size of the given array. Reason: We are traversing the array only once. Space Complexity: O(1) as we are using no extra space. But if they mention "the array might not have an majority element" for checking we again iterating , in this case T.C --> O(2N); 

Company Tags --> Flipkart Accolite Amazon Microsoft D-E-Shaw Google Nagarro Atlassian