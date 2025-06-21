➡️ problemLinks --> https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1 && https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/

✅ Brute Force --> vector<int> printLeadersBruteForce(int arr[], int n) {

  vector<int> ans;
  
  for (int i = 0; i < n; i++) {
    bool leader = true;

    //Checking whether arr[i] is greater than all 
    //the elements in its right side
    for (int j = i + 1; j < n; j++)
      if (arr[j] > arr[i]) {
          
        // If any element found is greater than current leader
        // curr element is not the leader.
        leader = false;
        break;
      }

    // Push all the leaders in ans array.
    if (leader)
    ans.push_back(arr[i]);

  }
  
  return ans;
}

//Time Complexity: ~O(n^2)
//Space Complexity: O(1)  

✅ MostOptimal --> 

