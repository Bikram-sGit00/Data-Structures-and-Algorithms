class Solution
{
public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr)
    {
        int largest = arr[0];
        int sLargest = -1;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] > largest)
            {
                sLargest = largest;
                largest = arr[i];
            }
            else if (arr[i] < largest && arr[i] > sLargest)
            {
                sLargest = arr[i];
            }
        }
        return sLargest;
    }
};