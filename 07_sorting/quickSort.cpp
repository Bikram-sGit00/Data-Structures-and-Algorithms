// https://www.geeksforgeeks.org/problems/quick-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=quick-sort

class Solution
{
public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(vector<int> &arr, int low, int high)
    {
        if (low < high)
        {
            int partiIndex = partition(arr, low, high);
            quickSort(arr, low, partiIndex - 1);
            quickSort(arr, partiIndex + 1, high);
        }
    }

public:
    // Function that takes last element as pivot, places the pivot element at
    // its correct position in sorted array, and places all smaller elements
    // to left of pivot and all greater elements to right of pivot.
    int partition(vector<int> &arr, int low, int high)
    {
        int i = low;
        int j = high;
        int pivot = arr[low];
        while (i < j)
        {
            while (arr[i] <= pivot && i <= high - 1)
            {
                i++;
            }
            while (arr[j] > pivot && j >= low + 1)
            {
                j--;
            }
            if (i < j)
                swap(arr[i], arr[j]);
        }
        swap(arr[low], arr[j]);
        return j;
    }
};
