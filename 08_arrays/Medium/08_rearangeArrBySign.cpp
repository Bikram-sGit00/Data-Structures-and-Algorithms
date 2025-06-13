➡️ problemLinks -->https://leetcode.com/problems/rearrange-array-elements-by-sign/description/


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

✅ MostOptimal Approach --> in optimal we will declare a answer vector and then we will iterate through the given array and check if the element is positive or negative and then we will put it in the answer array at the respective index...

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



➡️ problemLinks --> https://www.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1 (Another Variety where positives != negatives)

✅ Brute Force --> only brute force is possible here as positives and negatives are not equal 
class Solution {
  public:
    void rearrange(vector<int> &arr) {
        int n = arr.size();
        vector<int> positive,negative;
        for(int i = 0; i < n; i++){
            if(arr[i]>=0){
                positive.push_back(arr[i]);
            }
            else{
                negative.push_back(arr[i]);
            }
        }
        if(positive.size() > negative.size()){
            for(int i = 0; i<negative.size(); i++){
                arr[2*i] = positive[i];
                arr[2*i+1] = negative[i];
            }
            int index = negative.size()*2; // to know at which index put left-overs
            for(int i = negative.size(); i < positive.size(); i++){ //for left-over positive numbers 
                arr[index] = positive[i];
                index++;
            }
        }
        else{  //this will also cover if the sizes are equal
            for(int i = 0; i<positive.size(); i++){
            arr[2*i] = positive[i];
            arr[2*i+1] = negative[i];
            }
            int index = positive.size()*2; // to know at which index put left-overs
            for(int i = positive.size(); i < negative.size(); i++){ //for left-over positive numbers 
            arr[index] = negative[i];
            index++;
            }
        }
        
        
    }
};

// Time Complexity: O(2n)  ;  O(n) + min(positive, negative) + O(left-overs) = O(n) 
// Space Complexity: O(n)  ;  for storing positive and negative arrays