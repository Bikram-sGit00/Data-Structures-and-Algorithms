➡️ problemLinks --> https://leetcode.com/problems/longest-consecutive-sequence/

✅ Brute Force --> bool linearSearch(vector<int>&a, int num) {
    // This function checks if a number is present in the array using linear search.
    int n = a.size(); //size of array
    for (int i = 0; i < n; i++) {
        if (a[i] == num)
            return true;
    }
    return false;
}

int longestSuccessiveElements(vector<int>&a) {
    int n = a.size(); //size of array
    int longest = 1;  //Assuming the minimum length of consecutive sequence is 1
    //pick a element and search for its
    //consecutive numbers:
    for (int i = 0; i < n; i++) {
        int x = a[i]; //current element
        int cnt = 1; //count of consecutive numbers starting from x

        //search for consecutive numbers
        //using linear search:

        while (linearSearch(a, x + 1) == true) {
            x += 1; //increment x to check for next consecutive number
            cnt += 1; //increment count of consecutive numbers
        }

        longest = max(longest, cnt); // Update longest if current count is greater
    }
    return longest;
}

//Time Complexity: ~ O(n^2)
//Space Complexity: O(1)

✅ Better Approach --> here we will sort the array first and then find the longest consecutive sequence.
int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) return 0; // If the array is empty, return 0

    sort(nums.begin(), nums.end()); // Sort the array
    int longest = 1; // Initialize the longest sequence length
    int currentLength = 1; // Current consecutive sequence length

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1]) {
            continue; // Skip duplicates
        } else if (nums[i] == nums[i - 1] + 1) {
            currentLength++; // Increment current sequence length
        } else {
            longest = max(longest, currentLength); // Update longest if needed
            currentLength = 1; // Reset current sequence length
        }
    }
    return max(longest, currentLength); // Final check for the last sequence
}

//Time Complexity: O(n log n) due to sorting
//Space Complexity: O(1) if we sort in place, otherwise O(n) for the sorted array


// // ✅ Optimal Approach --> Using HashSet to achieve O(n) time complexity
// int longestConsecutive(vector<int>& nums) {
//     unordered_set<int> numSet(nums.begin(), nums.end()); // Insert all elements into a set
//     int longest = 0; // Initialize the longest sequence length

//     for (int num : nums) {
//         if (numSet.find(num) != numSet.end()) { // Check if the number is still in the set
//             numSet.erase(num); // Remove the number to avoid counting it again
//             int currentNum = num;
//             int currentLength = 1;

//             // Count consecutive numbers upwards
//             while (numSet.find(currentNum + 1) != numSet.end()) {
//                 currentNum++;
//                 currentLength++;
//                 numSet.erase(currentNum); // Remove to avoid counting again
//             }

//             currentNum = num; // Reset to the original number

//             // Count consecutive numbers downwards
//             while (numSet.find(currentNum - 1) != numSet.end()) {
//                 currentNum--;
//                 currentLength++;
//                 numSet.erase(currentNum); // Remove to avoid counting again
//             }

//             longest = max(longest, currentLength); // Update longest if needed
//         }
//     }
//     return longest; // Return the length of the longest consecutive sequence
// }


✅ Optimal Approach -->  class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int longest = 1;
        unordered_set<int> st;
        for(int i = 0;i < n; i++){ // inserting all elements in the unordered_set
          st.insert(nums[i]);
        }

        for(auto it : st){
          if(st.find(it - 1) == st.end()){ //checking till the end if have any lesser value than the element...
            int cnt = 1; // count of consecutive numbers starting from the current element
            int x = it; // the element 
            while(st.find(x + 1) != st.end()){ // checking if the next consecutive number exists in the set
              x = x+1; 
              cnt +=1; 
            }
            longest = max(cnt , longest);
          }
        }
        return longest;
    }
};

// Time Complexity: O(3N) , but if error detected in unordered_set then it will be O(4N) , worst than Brute Force
// Space Complexity: O(N) for the unordered_set