#include <bits/stdc++.h>
using namespace std;

int main()
{
    // creation
    unordered_map<string, int> mpp;

    // insertions:

    // i>
    pair<string, int> p1 = make_pair("luffy", 2);
    mpp.insert(p1);

    // ii>
    pair<string, int> p2("orewa", 3);
    mpp.insert(p2);

    // iii>
    mpp["d"] = 1; // will cerate new entry <"d",1>

    // if we again declare it
    mpp["d"] = 2; // will update the entry not add <"d",2>

    // search
    cout << mpp["d"] << endl;
    cout << mpp.at("d") << endl;

    cout << mpp["unknown"] << endl;    // if we try to access like this , this action creates an new entry thats why it will return us 0;
    cout << mpp.at("unknown") << endl; // but this will warn us

    // MCQ: if we declare mpp[] before mpp.at() , the mpp.at() will also give us 0 cause mpp[] already have create an empty entry ✅

    // size
    cout << mpp.size() << endl;

    // check presence
    cout << mpp.count("luffy") << endl;

    // erase
    mpp.erase("d");

    unordered_map<string, int>::iterator it = mpp.begin();
    while (it != mpp.end())
    {
        cout << it->first << " " << it->second << endl;
        it++;
    }
}
