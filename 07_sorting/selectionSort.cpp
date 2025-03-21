// https://www.geeksforgeeks.org/problems/selection-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=selection-sort;

class Solution
{
public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i <= n - 2; i++)
        {
            int mini = i;
            for (int j = i; j <= n - 1; j++)
            {
                if (arr[j] < arr[mini])
                {
                    mini = j;
                }
            }
            int temp=arr[mini];
            arr[mini]=arr[i];
            arr[i]=temp;
        }
    }
};
//not working...
// a = a + b;
// b = a - b;
// a = a - b;
arr[mini] = arr[mini] ^ arr[i];
arr[i] = arr[mini] ^ arr[i];
arr[mini] = arr[mini] ^ arr[i];