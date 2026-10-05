# Score of Parentheses

**LeetCode 856 — Score of Parentheses**

### Problem

Given a balanced parentheses string:

* `()` has score **1**
* `AB` has score **A + B**
* `(A)` has score **2 × A**

### Example

```text
Input:  (()(()))

        ( ( ) ( ( ) ) )
          ↓   ↓
          1   2

        Outer nesting doubles the score.

Output: 6
```

---

## Approach 1 — Stack

### Idea

Use a stack to remember the score **before entering each `(`**.

When we see:

```text
()
```

it contributes `1`.

When we see:

```text
(A)
```

the score becomes:

```text
2 * A
```

So:

```text
(A) → 2 × A
()  → 1
```

### Visual

For:

```text
(()())
```

Process:

```text
(        → push current score, reset score
(        → push current score, reset score
)        → () = 1
(        → push current score, reset score
)        → () = 1
)        → 2 × (1 + 1) = 4
```

### Code

```cpp
class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();
        stack<int> st;
        int score = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                // Save the score from before entering this bracket.
                st.push(score);

                // Start calculating the score inside this bracket.
                score = 0;
            }
            else{
                if(s[i - 1] == '('){
                    // We found "()".
                    // Its score is 1.
                    score = st.top() + 1;
                }
                else{
                    // We found "(A)".
                    // Its score is 2 * A.
                    score = st.top() + 2 * score;
                }

                // Remove the saved outer score.
                st.pop();
            }
        }

        return score;
    }
};
```

### Complexity

```text
Time  : O(n)
Space : O(n)    // stack can hold up to n/2 brackets
```

---

# Approach 2 — Depth / Nesting Level

### Key Idea

Instead of storing scores in a stack, track the **current depth**.

Every time we enter `(`:

```text
depth++
```

Every time we leave `)`:

```text
depth--
```

The important observation:

> A primitive `()` at depth `d` contributes `2^d`.

### Visual

For:

```text
(()())
```

Track the depth:

```text
(       depth = 1

(       depth = 2
)       depth = 1   → primitive "()" → 2^1 = 2

(       depth = 2
)       depth = 1   → primitive "()" → 2^1 = 2

)       depth = 0
```

So:

```text
2 + 2 = 4
```

### Why `2^depth`?

Each surrounding pair doubles the score:

```text
()          → 1

(())        → 2 × 1 = 2

((()))      → 2 × 2 = 4

(((())))    → 2 × 2 × 2 × 1 = 8
```

So when we find a primitive `()`:

```text
score += 2^depth
```

In C++, this can be written as:

```cpp
1 << depth
```

because:

```text
1 << 0 = 1
1 << 1 = 2
1 << 2 = 4
1 << 3 = 8
```

### Code

```cpp
class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        int depth = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                // Entering a new nested level.
                depth++;
            }
            else{
                // Leaving the current nested level.
                depth--;

                // If previous character was '(',
                // we found a primitive "()" pair.
                if(s[i - 1] == '('){
                    // Its score depends on its nesting depth.
                    score += (1 << depth);
                }
            }
        }

        return score;
    }
};
```

### Complexity

```text
Time  : O(n)
Space : O(1)
```

---

## Quick Revision

```text
RULES

()       → 1
AB       → A + B
(A)      → 2 × A
```

### Stack

```text
'(' → save previous score + reset
'()' → +1
'(A)' → +2A
```

### Depth

```text
'(' → depth++

')' → depth--

if "()" found:
    score += 2^depth
```

**Remember:**
The stack approach keeps the **previous scores**, while the depth approach only needs the **nesting level**.


# ✅ Company Tags (2026 Data)

> **`Amazon`** — Exact 6-month count not verifiable