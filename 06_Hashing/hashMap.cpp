#include <bits/stdc++.h>
using namespace std;

int main()
{
    // creation
    unordered_map<string, int> mpp;

    // insertions:

    // i>
    pair<string, int> p1 = make_pair("luffy", 3);
    mpp.insert(p1);

    // ii>
    pair<string, int> p2("orewa", 3);
    mpp.insert(p2);

    // iii>
    mpp["d"] = 1;

}
