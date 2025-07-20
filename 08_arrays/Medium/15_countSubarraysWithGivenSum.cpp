➡️ problemLinks --> https://www.geeksforgeeks.org/problems/subarray-range-with-given-sum2804/1

✅ Brute Force -->  in this approach, we will use three nested loops to find all subarrays and check if their sum equals k
int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int n = arr.size(); // size of the given array.
    int cnt = 0; // Number of subarrays:

    for (int i = 0 ; i < n; i++) { // starting index i
        for (int j = i; j < n; j++) { // ending index j

            // calculate the sum of subarray [i...j]
            int sum = 0;
            for (int K = i; K <= j; K++)
                sum += arr[K];

            // Increase the count if sum == k:
            if (sum == k)
                cnt++;
        }
    }
    return cnt;
}
// Time Complexity: ~O(n^3) where n is the size of the given array.
// Space Complexity: O(1) as we are not using any extra space.

✅ Better Approach --> 
int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int n = arr.size(); // size of the given array.
    int cnt = 0; // Number of subarrays:

    for (int i = 0 ; i < n; i++) { // starting index i
        int sum = 0;
        for (int j = i; j < n; j++) { // ending index j
            // calculate the sum of subarray [i...j]
            // sum of [i..j-1] + arr[j]
            sum += arr[j];

            // Increase the count if sum == k:
            if (sum == k)
                cnt++;
        }
    }
    return cnt;
}
// Time Complexity: ~O(n^2) where n is the size of the given array.
// Space Complexity: O(1) as we are not using any extra space.

✅ Optimized Approach --> in this approach, we will use a hash map to store the cumulative sum and its frequency. This way, we can find the number of subarrays with a given sum in a single pass.




✅ Company Tags -->  