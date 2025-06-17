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