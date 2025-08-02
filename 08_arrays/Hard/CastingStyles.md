C++: Safe Integer Addition & Casting Styles

When working with large integer additions in C++, especially with user input or problems like fourSum, it is critical to avoid integer overflow.

This README explains three common styles to safely handle such operations and the advantages/disadvantages of each.

🔥 The Problem: Integer Overflow

In C++, adding two large int values can overflow, even if you store the result in a long long. That's because the addition happens before the result is assigned:

int a = INT_MAX;
int b = 1;
long long sum = a + b; // ❌ Overflow happens BEFORE assignment

✅ Goal: Promote to long long before adding

There are three common approaches:

1. static_cast<long long>(...) (Modern C++)

long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[k] + nums[l];

✅ Pros:

Type-safe and explicit

Avoids accidental conversions

Preferred in modern C++ (C++11 and above)

❌ Cons:

Slightly longer syntax

2. (long long) C-style Cast (Traditional)

long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[l];

✅ Pros:

Shorter syntax

Works the same as static_cast

❌ Cons:

Less safe (can accidentally allow other implicit casts)

Not preferred in modern C++

3. Breaking into lines (Risky)

long long sum = nums[i] + nums[j]; // 🚨 May overflow!
sum += nums[k];
sum += nums[l];

✅ Pros:

Simple to read

❌ Cons:

Intermediate sum (nums[i] + nums[j]) happens in int => Risk of overflow!

✅ Recommended Style

Use static_cast<long long> on the first operand to ensure safe promotion:

long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[k] + nums[l];

This ensures that all subsequent additions happen in long long, preventing overflows.

🧠 TL;DR Comparison Table

Style

Safe from Overflow

Preferred in Modern C++

Notes

static_cast<long long>(...)

✅ Yes

✅ Yes

Best practice

(long long) cast

✅ Yes

⚠️ No

Okay but older style

Breaking into parts

❌ No

❌ No

Can overflow unexpectedly

📌 Example That Breaks

int a = INT_MAX;
int b = 1;
long long sum = a + b; // ❌ Overflow! Still stored in long long

But:

long long sum = static_cast<long long>(a) + b; // ✅ Safe

🔚 Conclusion

When working with problems involving large numbers in C++, like 3Sum, 4Sum, or cumulative sums:

Always cast the first operand to long long using static_cast to prevent overflow.

Happy Coding! 🚀

