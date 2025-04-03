class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int xorr=0; // Initialize xorr to 0
            for(int i=0;i<nums.size();i++){ // Iterate through the array
                // XOR the current element with xorr
                // The result will be the number that appears once
                // because all other numbers appear twice and cancel each other out
              xorr= xorr^nums[i];
            }
            return xorr;
        }
    };