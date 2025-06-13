➡️ problemLinks --> https://www.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1 && https://leetcode.com/problems/rearrange-array-elements-by-sign/description/


✅ Brute Force -->vector<int> RearrangebySign(vector<int>A, int n){
    
  // Define 2 vectors, one for storing positive 
  // and other for negative elements of the array.
  vector<int> pos;
  vector<int> neg;
  
  // Segregate the array into positives and negatives.
  for(int i=0;i<n;i++){
      
      if(A[i]>0) pos.push_back(A[i]);
      else neg.push_back(A[i]);
  }
  
  // Positives on even indices, negatives on odd.
  for(int i=0;i<n/2;i++){
      
      A[2*i] = pos[i];
      A[2*i+1] = neg[i];
  }
  
  
  return A;
    
}

✅ MostOptimal Approach --> in optimal we will declear a answer array and then we will iterate through the given array and check if the element is positive or negative and then we will put it in the answer array at the respective index...

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int positive = 0;
        int negative = 1;
        for(int i=0;i<n;i++){
          if(nums[i]<0){
            ans[negative]=nums[i];
            negative+=2;
          }
          else{
            ans[positive]=nums[i];
            positive+=2;
          }
        }
        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)

Company Tags --> Paytm VMWare Amazon Microsoft Intuit