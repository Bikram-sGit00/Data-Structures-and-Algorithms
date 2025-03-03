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

void explainQueue()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.emplace(4); // {1, 2, 4}
    cout << q.front() << " ";
    cout << q.back() << " ";
    q.pop(); // will remove 1

    q.back() += 5; // last + 5
    cout << q.back();

    // swap empty same as stack & are O(1)
}
void priorityQueue()
{
    // MAX HEAP
    priority_queue<int> pq;
    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.emplace(10);
    cout << pq.top() << " "; // prints 10 as it is the largest

    pq.pop(); // applies on the h.p element
    cout << pq.top();

    cout << endl;

    // MIN HEAP
    priority_queue<int, vector<int>, greater<int>> pQ;
    pQ.push(5);
    pQ.push(2);
    pQ.push(8);
    pQ.emplace(10);
    cout << pQ.top();

    // push-->logn    pop-->logn     top--O(1)
    // size swap empty function same as others
}

void understandingSets()
{
    set<int> st;
    st.insert(1); //{1}
    st.insert(4); //{1,4}
    st.insert(4); //{1,4} --> #Unique
    st.insert(2); //{1,2,4} --> #Sorted

    auto itr1 = st.find(2); // This action returns an iterator
    auto itr2 = st.find(3); // This action returns an iterator to the lastTh position

    st.erase(4); // takes logarithmic time

    int cnt = st.count(4); // returns 0 || 1
    cout << cnt;

    auto itr3 = st.find(2);
    st.erase(itr3); // takes constant time

    auto it1 = st.find(1);
    auto it2 = st.find(4);
    st.erase(it1, it2); // if set is {1,2,3,4,5} then output will : {4,5}

    // everything --> logn
}
void explainMultiSet()
{
    // Everything is same as set
    // only stores duplicate elements also
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);

    ms.erase(1); // all 1's erased

    int cnt = ms.count(1); // gives you number of ones

    ms.erase(ms.find(1)); // only a single one erased cause this deals with the address

    // ms.erase(ms.find(1), ms.find(1) + 2);

    // rest all function same as set
}
void unorderedSet()
{
    unordered_set<int> st;
    // lower _ bound and upper _ bound function does not works, rest all functions are same...
    // it don't stores in any particular order...
    // It has a better complexity O(1)
    // than set in most cases, except some when collision happens O(N)
}
void understandingMap()
{
    // Map stores unique keys in sorted data structure something similar to set data structure
    //  { key , value }
    map<int, int> mpp;
    // map<int, pair<int, int>> mpp;
    // map<pair<int, int>, int> mpp; // 🚀

    mpp[1] = 2; //...(i)
    // mpp2.emplace({3, 1}); //...(ii)     >>Remember sorted keys not values
    mpp.insert({2, 4}); //...(iii)

    // mpp[{4, 2}] = 10; // for the 🚀 line

    for (auto itr : mpp)
    {
        cout << itr.first << " " << itr.second << endl;
    }

    cout << mpp[1] << " "; // Will give us 1key's element
    cout << mpp[5] << " "; // if doesn't exist gives us null/0

    // auto it = mpp.find(1); & if doesn't exist will point at the end
    // cout << *(it).second;
}
void multiMap()
{
    // Now we can store values in same keys
    // only map[key] cannot be used here
    // Sorted
    // logn
}
void unorderedMap()
{
    // Unsorted
    // keys will be unique
    // logn
    // worst case: O(n)
}
void algorithm()
{
    sort(a, a + n);           //{1,3,6,5}-->{1,3,5,6} ,where a means start and a+1 means after 5
    sort(v.begin(), v.end()); // OR if we are using vector

    sort(a + 2, a + 4); // sorting in a particular range

    sort(a, a + n, greater<int>); // sorting in descending order (greater is a comparator)


}
int main()
{

    cout << "\nCompilation Done 🚀✨";

    return 0;
}
