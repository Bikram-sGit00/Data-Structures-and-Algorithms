➡️ problemLinks --> https://leetcode.com/problems/sum-of-subarray-minimums/  &&  https://www.geeksforgeeks.org/problems/sum-of-subarray-minimum/1

✅ Brute Force -->  class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(); // Array size
        long long ans = 0; // Stores sum of all subarray minimums
        int mod = 1e9 + 7; // Prevents answer from getting too large

        for (int i = 0; i < n; i++) { // Fix starting point of subarray
            int mini = arr[i]; // Minimum of current subarray starts as arr[i]

            for (int j = i; j < n; j++) { // Extend subarray one element at a time
                mini = min(mini, arr[j]); // Update minimum after adding arr[j]

                ans = (ans + mini) % mod; // Add current subarray's minimum
            }
        }

        return ans; // Return final sum
    }
};

Time Complexity : O(n^2)
Space Complexity : O(1)

✅ Optimized Approach --> class Solution {
public:

    vector<int> findNSE(vector<int>& arr ,int n){
        stack<int> st; // Monotonic stack → stores indices
        vector<int> NSE(n); // NSE index for every element

        for(int i = n - 1; i >= 0; i--){ // Right → Left
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop(); // NSE is STRICTLY smaller → pop >=
            NSE[i] = st.empty() ? n : st.top(); // No NSE → n boundary
            st.push(i); // Store index, not value
        }

        return NSE; // Return all NSE indices
    }


    vector<int> findPSEE(vector<int>& arr,int n){
        stack<int> st; // Monotonic stack → stores indices
        vector<int> PSEE(n); // PSEE index for every element

        for(int i = 0; i < n; i++){ // Left → Right
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop(); // PSEE allows equal → pop only >
            PSEE[i] = st.empty() ? -1 : st.top(); // No PSEE → -1 boundary
            st.push(i); // Store index, not value
        }

        return PSEE; // Return all PSEE indices
    }


    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(); // Array size
        long long sum = 0; // Final answer
        int mod = (int)(1e9 + 7); // Required modulo

        vector<int> NSE = findNSE(arr,n); // Next strictly smaller
        vector<int> PSEE = findPSEE(arr,n); // Previous smaller/equal

        for(int i = 0; i < n; i++){ // Calculate each element's contribution
            int leftChoices = i - PSEE[i]; // Valid starting points
            int rightChoices = NSE[i] - i; // Valid ending points

            // sum += (leftChoices * rightChoices * arr[i] + 1LL) % mod;
            sum = (sum + 1LL * leftChoices * rightChoices * arr[i]) % mod; // Contribution = value × left × right
        }

        return sum; // Final sum of all subarray minimums
    }
};

PSEE → <= → pop >
NSE  → <  → pop >=
That `>` vs `>=` is the key duplicate-handling trick.

Time Complexity : O(n) + O(n) + O(n) = O(3n) = O(n) , cause we are using 2 monotonic stacks and a for loop of size n

Space Complexity : O(n) + O(n) = O(2n) = O(n) , cause we are using 2 stacks of size n

✅ Company Tags -->  NPCI