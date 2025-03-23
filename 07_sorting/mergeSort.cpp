// https://www.geeksforgeeks.org/problems/merge-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=merge-sort
class Solution
{
public:
    void merge(vector<int> &arr, int low, int mid, int high) // function to merge the two halves of the array
    {
        vector<int> temp; // temporary array to store the sorted elements

        // [ low to mid is the left half of the array and mid+1 to high is the right half of the array]
        int left = low;      // left pointer
        int right = mid + 1; // right pointer

        while (left <= mid && right <= high) // comparing the elements of the two halves and storing the smaller element in the temporary array
        {
            if (arr[left] <= arr[right]) // if the element of the left half is smaller than the element of the right half...
            {
                temp.push_back(arr[left]);
                left++;
            }
            else // if the element of the right half is smaller than the element of the left half...
            {
                temp.push_back(arr[right]);
                right++;
            }
        }
        while (left <= mid) // if there are still some elements left in the left half of the array...
        {
            temp.push_back(arr[left]);
            left++;
        }
        while (right <= high) // if there are still some elements left in the right half of the array...
        {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = low; i <= high; i++) // copying the sorted elements from the temporary array to the original array
        {
            arr[i] = temp[i - low];
        }
    }
    void mS(vector<int> &arr, int low, int high) // function to divide the array into two halves & merge them...
    {
        if (low >= high) // base case
            return;
        int mid = (low + high) / 2; // finding the mid point of the array  [ low to mid is the left half of the array and mid+1 to high is the right half of the array]
        mS(arr, low, mid);          // calling the function recursively for the left half of the array
        mS(arr, mid + 1, high);     // calling the function recursively for the right half of the array
        merge(arr, low, mid, high); // merging the two halves of the array
    }
    void mergeSort(vector<int> &arr, int left, int right)
    {
        mS(arr, 0, arr.size() - 1); // passing the given array and starting and ending index of the array
    }
};