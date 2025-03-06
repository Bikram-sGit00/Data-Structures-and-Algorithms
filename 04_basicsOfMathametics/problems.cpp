#include <iostream>
using namespace std;

1 >> Reverse a number;
class Solution
{
public:
    long int reverse(int x)
    {
        long long int revNum = 0;
        while (x > 0 || x < 0)
        {
            if ((revNum > INT_MAX / 10) || (revNum < INT_MIN / 10))
            {
                return 0; // Return 0 if reversing x would cause overflow/underflow
            }
            long long int ld = x % 10;
            revNum = (revNum * 10) + ld;
            x /= 10;
        }

        return revNum;
    }
};

2 >> check palindrome;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        long int revNum = 0;
        long int dup = x;
        while (x > 0)
        {
            long int ld = x % 10;
            revNum = (revNum * 10) + ld;
            x /= 10;
        }
        if (dup == revNum)
            return true;
        else
            return false;
    }
};

3 >> Armstrong Numbers;

long long int revNum = 0;
while (x > 0 || x < 0)
{
    if ((revNum > INT_MAX / 10) || (revNum < INT_MIN / 10))
    {
        return 0; // Return 0 if reversing x would cause overflow/underflow
    }
    long long int ld = x % 10;
    long long int sum += (ld * ld * ld);
    x /= 10;
}

return revNum;

4 >> print all divisors;
vector<int> ls;
for (int i; i * i <= n; i++)
{
    if (n % i == 0)
    {
        ls.push_back(i);
        if ((n / i) != i)
        {
            ls.push_back((n / i));
        }
    }
}
sort(ls.begin(), ls.end());
for (auto itr : ls)
    cout << itr << " ";

5 >> check prime;
int cnt = 0;
for (i = 0; i * i <= n; i++)
{
    if (n % i == 0)
    {
        cnt++;
        if ((i / 2) != i)
            cnt++;
    }
}
if (cnt == 2)
    cout << "prime";
else
    cout << "not prime";

6 >> GCD Or HCF;

// will take linear time complexity
for (int i = MIN(n1, n2); i >= 1; i--)
{
    if (n1 % i == 0 && n2 % i == 0)
    {
        cout << i;
        break; // will break the for loop
    }
}
