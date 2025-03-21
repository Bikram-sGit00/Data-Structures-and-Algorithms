// https://www.geeksforgeeks.org/problems/insertion-sort/0?category%5B%5D=Algorithms&page=1&query=category%5B%5DAlgorithmspage1&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=insertion-sort

class Solution
{
public:
    // Please change the array in-place
    void insertionSort(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i <= n - 1; i++)
        {
            int j = i;
            while (j > 0 && arr[j - 1] > arr[j])
            {
                int temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
                j--;
            }
        }
    }
};
