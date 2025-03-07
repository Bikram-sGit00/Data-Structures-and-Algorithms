#include <bits/stdc++.h>
using namespace std;

void revArr(int i, vector<int> &arr, int n)
{
    if (i >= n / 2)
        return;
    swap(arr[i], arr[(n - i - 1)]);
    revArr(i + 1, arr, n);
}

int main()
{
    int n = 5;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    revArr(0, arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
