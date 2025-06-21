➡️ problemLinks --> https://leetcode.com/problems/next-permutation/

✅ MostOptimal -->
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(),nums.end());
        int pivot = -1;
        int n = nums.size();

        //find the pivot
        for(int i = n-2; i>= 0; i--){
          if(nums[i] < nums[i+1]){
            pivot = i;
            break;
          }
        }

        //edge-case
        if(pivot == -1){
          reverse(nums.begin(),nums.end());  // use this instead of manual approach for reliability...  && in place changes...
          return;  //very very important...

          // int i = nums[0];
          // int j = nums[nums.size()-1];
          // while(i <= j){
          //   swap(nums[i],nums[j]);
          //   i++;
          //   j--;
          // }
          // return;
        }

        //swap with right most
        for(int i = n-1; i > pivot; i--){
          if(nums[i] > nums[pivot]){
          swap(nums[i],nums[pivot]);
          break;
        }
        }

        //reverse the remaining 
        // int i = pivot +1;
        // int j = n-1;
        // while(i < j){
        //   swap(nums[i++],nums[j--]);
        //   break; // no need 
        // }
        // sort(nums.begin()+pivot+1,nums.end());  // O(N log N)
        reverse(nums.begin() + pivot + 1 ,nums.end()); // use this cause O(N)
        
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1) or O(N) if we consider the input vector as additional space, but since we are modifying it in place, we can consider it O(1).
// Note: The use of reverse is more efficient than sorting the remaining elements, as it runs in O(N) time complexity compared to O(N log N) for sorting.

Company Tags --> Infosys Flipkart Amazon Microsoft FactSet Hike MakeMyTrip Google Qualcomm Salesforce