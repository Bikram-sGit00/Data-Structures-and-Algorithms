#include <bits/stdc++.h> // This will include all standard libraries
using namespace std;

void pair() // utility library
{
    pair<int, double> p = {1, 3.27}; // pair of two integers into a single entity
    cout << p.first << " " << p.second << endl;

    pair<int, pair<int, int>> p1 = {1, {3, 4}}; // nested pair for storing three values into a single entity
    cout << p1.first << " " << p1.second.first << " " << p1.second.second << endl;

    pair<int, int> arr[] = {{1, 2}, {2, 3}, {3, 4}}; // storing multiple pairs in an array
    cout << arr[0].first << " " << arr[0].second << endl;
}

int main()
{

    return 0;
}