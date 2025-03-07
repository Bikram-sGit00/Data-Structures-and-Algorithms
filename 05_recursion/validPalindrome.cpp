#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string &s)
    {
        int i = 0;
        if (i >= s.size() / 2)
            return true;
        if (s[i] != s[s.size() - i - 1])
            return false;
        i++;
        return isPalindrome(s);
    }
};

//this code will work fine but not with alphanumeric characters will be fixing soon...