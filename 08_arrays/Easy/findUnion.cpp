class Solution
{
public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b)
    {
        int n1 = a.size();
        int n2 = b.size();
        int i = 0;
        int j = 0;
        vector<int> unionArr;

        while (i < n1 && j < n2)
        {
            if (a[i] <= b[j])
            {
                if (unionArr.size() == 0 || unionArr.back() != a[i])
                { // checking if the next element is equal or not;
                    unionArr.push_back(a[i]);
                }
                i++;
            }
            else
            {
                if (unionArr.size() == 0 || unionArr.back() != b[j])
                {
                    unionArr.push_back(b[j]);
                }
                j++;
            }
        }
        // if anyone get exhausted

        while (j < n2)
        {
            if (unionArr.size() == 0 || unionArr.back() != b[j])
            {
                unionArr.push_back(b[j]);
            }
            j++;
        }
        while (i < n1)
        {
            if (unionArr.size() == 0 || unionArr.back() != a[i])
            { // checking if the next element is equal or not;
                unionArr.push_back(a[i]);
            }
            i++;
        }
        return unionArr;
    }
};

// Time Complexity: O(n1+n2) where n1 and n2 are the sizes of the two arrays.
// Space Complexity: O(n1+n2) in order to return the union array.
// Asked In: Amazon;
