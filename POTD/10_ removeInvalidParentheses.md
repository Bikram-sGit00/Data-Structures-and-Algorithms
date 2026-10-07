# Remove Invalid Parentheses

## Problem

Given a string containing letters and parentheses, remove the **minimum number of invalid parentheses** so that the resulting strings are valid.

Return **all possible valid strings** with maximum length.

---

## Approach — Recursion / Backtracking

At every parenthesis, we have **2 choices**:

```text
Keep the parenthesis
        OR
Remove the parenthesis
```

For normal characters, we **must keep them**.

We maintain:

* `count` → current balance of `(` and `)`
* `currStr` → string we are currently building
* `maxLen` → maximum valid string length found so far
* `st` → stores all valid strings having `maxLen`

### Balance idea

```text
'(' → count + 1
')' → count - 1
```

A string is valid when:

```text
count == 0
```

If:

```text
count < 0
```

the current path already has more `)` than `(`, so we can immediately stop exploring it.

---

## Recursion Visual

For every parenthesis:

```text
                 '(' or ')'
                     |
             ┌───────┴───────┐
             │               │
           KEEP            REMOVE
             │               │
        update count     count unchanged
```

For normal characters:

```text
letter
  |
  ↓
always KEEP
```

---

## Why `maxLen`?

We need to remove the **minimum number of parentheses**.

Since the original string length is fixed:

```text
Minimum removals
        ↓
Maximum remaining length
```

So whenever we find a valid string:

```cpp
if(currStr.length() > maxLen)
```

we found a better answer.

Therefore:

1. Update `maxLen`
2. Clear previous answers
3. Store the new string

If another valid string has the same length, store it too.

---

## Code

```cpp
class Solution {
public:
    int n;
    int maxLen;
    unordered_set<string> st;

    void solve(string& s, int i, string& currStr, int count){
        // If ')' makes the balance negative, this path can never become valid.
        if(count < 0) return;

        // We have processed the complete string.
        if(i == n){
            // A valid string must have equal '(' and ')' count.
            if(count == 0){

                // Found a longer valid string.
                // This means fewer parentheses were removed.
                if(currStr.length() > maxLen){
                    maxLen = currStr.length();
                    st.clear();
                }

                // Store all valid strings having the maximum length.
                if(currStr.length() == maxLen)
                    st.insert(currStr);
            }
            return;
        }

        // Normal characters are not parentheses,
        // so they cannot make the string invalid.
        // We must always keep them.
        if(s[i] != '(' && s[i] != ')'){
            currStr.push_back(s[i]);
            solve(s, i + 1, currStr, count);
            currStr.pop_back();
            return;
        }

        // Choice 1: KEEP the current parenthesis.
        currStr.push_back(s[i]);

        // '(' increases balance, ')' decreases balance.
        solve(s, i + 1, currStr,
              (s[i] == '(') ? count + 1 : count - 1);

        // Backtrack.
        currStr.pop_back();

        // Choice 2: REMOVE the current parenthesis.
        // count remains unchanged because we skipped it.
        solve(s, i + 1, currStr, count);
    } 
    
    vector<string> removeInvalidParentheses(string s) {
        n = s.length();
        maxLen = 0;

        string currStr = "";

        solve(s, 0, currStr, 0);

        return vector<string>(st.begin(), st.end());
    }
};
```

---

## Example

```text
s = "()())()"
```

The recursion tries different combinations of keeping/removing parentheses.

Valid maximum-length results can be:

```text
()()()
(())()
```

Both have the same maximum length, so both are stored.

```text
maxLen = 6

st = {
    "()()()",
    "(())()"
}
```

---

## Important Backtracking Pattern

The main pattern to remember is:

```cpp
currStr.push_back(s[i]);

solve(...);       // explore KEEP

currStr.pop_back();

solve(...);       // explore REMOVE
```

This is the standard:

```text
DO
 ↓
RECURSE
 ↓
UNDO
```

pattern.

---

## Complexity

At every parenthesis we have **2 choices**:

```text
KEEP
REMOVE
```

So in the worst case:

### Time

```text
O(2^n × n)
```

`2^n` possible choices, and storing/comparing strings can take up to `O(n)`.

### Auxiliary Recursion Space

```text
O(n)
```

for:

* recursion stack
* `currStr`

### Result Storage

In the worst case, we may store many valid strings:

```text
O(2^n × n)
```

because `unordered_set<string>` stores the resulting strings.

---

## Pattern to Remember

> **Remove Invalid Parentheses = Backtracking + Balance + Maximum Length**

At every parenthesis:

```text
Keep OR Remove
```

Prune when:

```text
count < 0
```

At the end:

```text
count == 0 → valid
```

Among valid strings:

```text
maximum length → minimum removals
```
