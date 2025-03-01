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

void insertionInVector()
{
    // Remember insert in an vector is costlier😶‍🌫️...
    vector<int> v = {1, 2, 3, 4, 5};
    v.insert(v.begin() + 2, 5); // inserting 10 at 2nd index
    for (auto it : v)
    {
        cout << it << " ";
    }

    cout << endl;

    v.insert(v.begin() + 2, 3, 10); // inserting 10 three times at 2nd index
    for (auto it : v)
    {
        cout << it << " ";
    }

    cout << endl;

    vector<int> v1 = {7, 8, 9};
    v.insert(v.begin() + 2, v1.begin(), v1.end()); // inserting elements of v1 at 2nd index from v1.begin() to v1.end()
    for (auto it : v)
    {
        cout << it << " ";
    }

    cout << endl;

    cout << v.size() << endl;     // How many elements are there in the vector
    cout << v.capacity() << endl; // returns the capacity of the vector
    // cout << v.pop_back() << endl; // removes the last element of the vector

    vector<int> swap1 = {1, 2, 3, 4, 5};
    vector<int> swap2 = {6, 7, 8, 9, 10};
    swap1.swap(swap2);
    for (auto its : swap2)
    {
        cout << its << " "; // we don't need *its as its is not a pointer
    }

    v.clear();                 // removes all the elements of the vector
    cout << v.empty() << endl; // returns 1 if the vector is empty else 0
}

void understandingList()
{
    list<int> ls;

    ls.push_back(2);
    ls.emplace_back(4);
    ls.push_front(6);
    ls.emplace_front(8);
    for (auto it : ls)
    {
        cout << it << " ";
    }
    // Rest functions are same as vector
}
void understandingDeque()
{
    deque<int> dQ;

    dQ.push_back(2);
    dQ.emplace_back(4);
    dQ.push_front(6);
    dQ.emplace_front(8);
    for (auto it : dQ)
    {
        cout << it << " ";
    }
}

void understandingStack()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.emplace(5);
    cout << st.top() << " "; // Will Show us 5 but not remove 5
    st.pop();                // Will Remove 5
    cout << st.top() << endl;
    cout << st.size() << " ";
    cout << st.empty();

    stack<int> st1, st2;
    st1.swap(st2);

    // Main operations of stack i.e top(),pop(),push() are --> O(1)
}

int main()
{
    understandingStack();
    cout << "\nCompilation Done 🚀✨";

    return 0;
}
