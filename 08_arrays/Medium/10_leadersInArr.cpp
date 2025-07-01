➡️ problemLinks --> https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1 && https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/

✅ Brute Force --> vector<int> printLeadersBruteForce(int arr[], int n)
{
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    bool leader = true;
    for (int j = i + 1; j < n; j++) // Checking whether arr[i] is greater than all the elements in its right side
      if (arr[j] > arr[i])
      {
        leader = false; // If any element found is greater than current leader ,current element is not the leader...
        break;
      }
    
    if (leader) ans.push_back(arr[i]); // Pushing all the leaders in ans array 

  }
  return ans;
}

// Time Complexity: ~O(n^2)
// Space Complexity: O(1) Or O(n) Ykw...

✅ MostOptimal --> // We will traverse from the last element
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int maxRight = -1; // Last element will be -1 Or can be INT_MIN
        for (int i = n - 1; i >= 0; i--) {
            int current = arr[i];   // Store the current value
            arr[i] = maxRight;      // Replace with the max to the right
            maxRight = max(maxRight, current); // Update max
        }
        return arr;
    }
};
// Time Complexity: O(n) And if we have to sort the order then it will be O(n log n) 
// Space Complexity: O(1) Or O(n) Ykw...

So here we have an vector so we can we can modify the array but if the question states that we should return another vector/array so we can create another "answer" vector / array and then we can return it depending on the question...