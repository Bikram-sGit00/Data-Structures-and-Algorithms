// Brute Force Approach
//  Time Complexity: O(n^3)
//  Space Complexity: O(1)
int getLongestSubarray(vector<int> &a, long long k)
{
    int n = a.size(); // size of the array.

    int len = 0;
    for (int i = 0; i < n; i++)
    { // starting index
        for (int j = i; j < n; j++)
        {                    // ending index
            s += a[j];       // OR , O(n^2) & O(1) space complexity;
            long long s = 0; // add all the elements of subarray = a[i...j]:
            for (int K = i; K <= j; K++)
            {
                s += a[K];
            }

            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}

// Better Approach
//  Time Complexity: O(n^2)
//  Space Complexity: O(1)
