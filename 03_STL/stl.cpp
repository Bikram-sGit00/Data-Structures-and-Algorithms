#include <bits/stdc++.h> // This will include all standard libraries
using namespace std;

void understandingPairs() // utility library
{
    pair<int, double> p = {1, 3.27}; // pair of two integers into a single entity
    cout << p.first << " " << p.second << endl;

    pair<int, pair<int, int>> p1 = {1, {3, 4}}; // nested pair for storing three values into a single entity
    cout << p1.first << " " << p1.second.first << " " << p1.second.second << endl;

    pair<int, int> arr[] = {{1, 2}, {2, 3}, {3, 4}}; // storing multiple pairs in an array
    cout << arr[0].first << " " << arr[0].second << endl;
}

void understandingVectors()
{
    // vectors are containers that can store multiple values of same type
    // We need vectors cause arrays are constant/static in size
    vector<int> v;
    v.push_back(1);    // adding elements to the vector
    v.emplace_back(2); // similar to push_back but more efficient or fast as it constructs the element in place rather than copying it

    vector<pair<int, int>> vec;
    vec.push_back({1, 2});  // adding pair of integers to the vector
    vec.emplace_back(3, 4); // no need to use curly braces

    vector<int> var1(5);     // vector of size 5 with all elements as 0 or any garbage value depends on the compiler
    vector<int> var2(5, 10); // vector of size 5 with all elements as 10

    vector<int> v1(5, 20);
    vector<int> v2(v1); // copy of v1

    // UNDERSTANDING ITERATORS
    vector<int>::iterator itr = v.begin(); // iterator is a pointer that points to the elements of the vector
    itr++;                                 // moving the iterator to the next element
    cout << *itr << endl;

    vector<int>::iterator end = v.end(); // end points to the next of the last element so to get the last element we need to decrement it else it will give garbage value
    end--;                               // moving the iterator to the last element
    cout << *end << endl;

    // vector<int>::iterator reverseEnd = v.rend(); // points to the next of the first element so to get the first element we need to decrement it else it will give garbage value
    // // cout << *reverseEnd << endl;

    // vector<int>::iterator reverseBegin = v.rbegin(); // points to the last element
    // cout << *reverseBegin << endl;

    cout << v[0] << endl;     // accessing elements using index
    cout << v.at(0) << endl;  // accessing elements using at function
    cout << v.back() << endl; // returns the last element of the vector
    cout << v.front() << endl;

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    for (auto it = v.begin(); it != v.end(); it++) // auto keyword automatically detects the data type of the iterator
    {
        cout << *it << " ";
    }
    for (auto it : v) // range based loop
    {
        cout << it << " "; // :v means for each element in v
    }
}

void deletionInVector()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    v.erase(v.begin() + 2); // this action will reshuffle the vector
    for (auto it : v)
    {
        cout << it << " ";
    }

    cout << endl;

    v.erase(v.begin() + 2, v.begin() + 5); // remember that the second argument +5 means it will delete the element at 5th index or 4th element
    for (auto it : v)
    {
        cout << it << " ";
    }
}

int main()
{
    deletionInVector();
    cout << "\nCompilation Done 🚀✨";

    return 0;
}
