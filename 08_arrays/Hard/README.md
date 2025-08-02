/*
README: Safe Integer Addition & Casting Styles in C++
Place this file inside any relevant folder (like hard/) in your GitHub repo.
GitHub will automatically render it at the bottom of the folder page.
*/

/* 🔥 Problem: Integer Overflow */
// Adding large int values may overflow before being stored in long long.

int a = INT_MAX;
int b = 1;
long long sum = a + b; // ❌ Overflow happens before assignment

/* ✅ Goal: Promote to long long before any addition */

/*

static_cast(...) // Modern C++
=============================================
*/
long long sum1 = static_cast(nums[i]) + nums[j] + nums[k] + nums[l];

// Pros:
// - Type-safe and explicit
// - Avoids accidental conversions
// - Preferred in C++11 and above

// Cons:
// - Slightly longer syntax

/*

(long long) Cast // Traditional C-style
=============================================
*/
long long sum2 = (long long)nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[l];

// Pros:
// - Shorter syntax
// - Works similarly to static_cast

// Cons:
// - Less type-safe
// - Not recommended in modern C++

/*

Breaking into lines // Risky
=============================================
*/
long long sum3 = nums[i] + nums[j]; // 🚨 May overflow!
sum3 += nums[k];
sum3 += nums[l];

// Pros:
// - Simple and readable

// Cons:
// - Intermediate sum in int may overflow

/* ✅ Recommended Style */
long long sum4 = static_cast(nums[i]) + nums[j] + nums[k] + nums[l]; // ✅ Safe

/*
📌 Comparison Table:

Style

Safe

Modern C++ Preferred

Notes

static_cast(...)

Yes

Yes

✅ Best practice

(long long) cast

Yes

No

⚠️ Okay but old-school

Split addition

No

No

❌ Can overflow midway

*/

/*
🔚 Conclusion:
Always cast the first operand to long long using static_cast to avoid overflow in C++.
This is especially important in problems like 3Sum, 4Sum, or when summing large numbers.
*/

