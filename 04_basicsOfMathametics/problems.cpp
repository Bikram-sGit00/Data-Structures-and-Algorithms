#include <iostream>
using namespace std;

>> Reverse a number
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