class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            int n = nums.size();
            int temp=arr[0];
            for(int i=1;i<n;i++){
                nums[i-1]=nums[i];  
            }
            nums[n-1]=temp;
        }
    };