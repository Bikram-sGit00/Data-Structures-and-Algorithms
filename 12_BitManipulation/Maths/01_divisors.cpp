https://www.geeksforgeeks.org/problems/all-divisors-of-a-number/1

vector<int> ls;      // Stores all divisors of n

// =======================================================
// Why do we loop only till sqrt(n)?
//
// Example: n = 36
//
// Divisors always come in PAIRS.
//
// 1  <--> 36
// 2  <--> 18
// 3  <--> 12
// 4  <--> 9
// 6  <--> 6   <-- Middle point
//
// Notice:
//
// After sqrt(36)=6,
// the remaining divisors are just the "other half"
// that we've already discovered.
//
// So checking after sqrt(n) is a COMPLETE WASTE.
//
// Therefore,
// instead of checking from 1...36,
// we only check from 1...6.
//
// Time Complexity:
// O(sqrt(n))
// =======================================================

for (int i = 1; i * i <= n; i++)
{
    // Check whether i divides n perfectly.
    // (% == 0 means NO remainder)
    if (n % i == 0)
    {
        // --------------------------------------------
        // First divisor found.
        //
        // Example:
        // n = 36
        // i = 3
        //
        // 3 divides 36.
        // So 3 is definitely a divisor.
        // --------------------------------------------
        ls.push_back(i);

        // --------------------------------------------
        // Every divisor has a partner.
        //
        // Example:
        // n = 36
        // i = 3
        //
        // Partner = 36 / 3 = 12
        //
        // Pair:
        // (3 , 12)
        //
        // Since we've already found 3,
        // immediately store its partner 12.
        // --------------------------------------------

        // But...
        // Sometimes both numbers are SAME.
        //
        // Example:
        //
        // n = 36
        // i = 6
        //
        // Partner = 36/6 = 6
        //
        // Pair becomes (6,6)
        //
        // We should store 6 ONLY ONCE.
        if ((n / i) != i)
        {
            ls.push_back(n / i);
        }
    }
}

// Time Complexity: O(sqrt(n))
// Space Complexity: O(sqrt(n))