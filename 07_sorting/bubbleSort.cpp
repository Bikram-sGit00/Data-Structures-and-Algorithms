// https://www.geeksforgeeks.org/problems/bubble-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bubble-sort

class Solution
{
public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(vector<int> &arr)
    {
        // Your code here
        for (int i = (arr.size() - 1); i >= 1; i--)
        {
            int didSwap = 0; // if no swapping is done in the inner loop, then the array is already sorted
            for (int j = 0; j <= i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = temp;
                    didSwap = 1;
                }
                if (didSwap == 0)
                {
                    break;
                }
            }
        }
    }
};

// Time Complexity: O(n^2)  [worst or average case]
// Time Complexity: O(n)    [best case]
