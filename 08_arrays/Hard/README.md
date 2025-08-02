# Safe Integer Addition & Casting Styles in C++

---

## 🔥 Problem: Integer Overflow

Adding large `int` values can overflow even if the result is stored in a `long long`:

```cpp
int a = INT_MAX;
int b = 1;
long long sum = a + b; // ❌ Overflow happens BEFORE assignment
```

---

## ✅ Goal: Promote to `long long` BEFORE any addition

---

## 1. `static_cast<long long>(...)` – Modern C++

```cpp
long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[k] + nums[l];
```

✅ **Pros:**
- Type-safe and explicit
- Avoids accidental conversions
- Preferred in C++11 and above

❌ **Cons:**
- Slightly longer syntax

---

## 2. `(long long)` Cast – Traditional C-style

```cpp
long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[l];
```

✅ **Pros:**
- Shorter syntax
- Works similarly to `static_cast`

❌ **Cons:**
- Less type-safe
- Not recommended in modern C++

---

## 3. Breaking into lines – ❌ Risky

```cpp
long long sum = nums[i] + nums[j]; // 🚨 May overflow!
sum += nums[k];
sum += nums[l];
```

✅ **Pros:**
- Simple and readable

❌ **Cons:**
- Intermediate result (`nums[i] + nums[j]`) happens in `int` => **can overflow!**

---

## ✅ Recommended Style

Always cast the **first operand** to `long long`:

```cpp
long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[k] + nums[l]; // ✅ Safe
```

---

## 📌 Comparison Table

| Style                         | Safe | Modern C++ Preferred | Notes                    |
|------------------------------|------|----------------------|---------------------------|
| `static_cast<long long>(...)`| ✅    | ✅                   | ✅ Best practice          |
| `(long long)` cast           | ✅    | ⚠️ No                | Okay but older style     |
| Split addition               | ❌    | ❌                   | ❌ Can overflow midway    |

---

## 🔚 Conclusion

When working with large integer sums (e.g., in problems like `3Sum`, `4Sum`, or cumulative totals):

> **Always cast the first operand to `long long` using `static_cast` to prevent overflow.**

Happy coding! 🚀