➡️ problemLinks --> https://www.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1 && https://leetcode.com/problems/rearrange-array-elements-by-sign/description/


✅ Brute Force Approach -->vector<int> RearrangebySign(vector<int>A, int n){
    
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

✅ Better Approach --> 

✅ mostOptimal -->


Company Tags --> 