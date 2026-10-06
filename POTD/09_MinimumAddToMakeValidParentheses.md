# Minimum Add to Make Parentheses Valid

## Problem

Given a string `s` containing only `'('` and `')'`, find the **minimum number of parentheses** we need to add to make the string valid.

### Example

```text
Input:  "())"
Output: 1

"())" → "()()"
       ↑
   add one '('
```

---

## Approach — Greedy

We keep track of two things:

* `needClose` → how many `')'` are currently needed to match the existing `'('`
* `needOpen` → how many `'('` we need to add because we found an unmatched `')'`

### Main idea

```text
'('  → needs a ')' later
       needClose++

')'  → if there is an opening '(' to match:
       needClose--

       otherwise:
       this ')' is unmatched
       needOpen++
```

At the end:

```text
needClose → unmatched '(' → need to add ')'
needOpen  → unmatched ')' → need to add '('

Answer = needClose + needOpen
```

### Visual

For:

```text
"())("
```

Process:

```text
(    → needClose = 1
)    → needClose = 0
)    → no '(' available
       needOpen = 1
(    → needClose = 1
```

At the end:

```text
needOpen  = 1   → add '('
needClose = 1   → add ')'

Answer = 1 + 1 = 2
```

---

## Code

```cpp
class Solution {
public:
    int minAddToMakeValid(string s) {
        int needClose = 0;
        int needOpen = 0;

        for(int i = 0; i < s.length(); i++){
            // Every '(' needs one ')' to match it later.
            if(s[i] == '(') needClose++;

            // Current ')' can match an already waiting '('.
            else if(needClose > 0 && s[i] == ')') needClose--;

            // No '(' is available for this ')',
            // so we need to add one '(' before it.
            else needOpen++; 
        }

        // needClose = unmatched '('
        // needOpen  = unmatched ')'
        return needClose + needOpen;
    }
};
```

---

## Complexity

### Time: `O(n)`

We traverse the string exactly once.

```text
n characters → one loop → O(n)
```

### Space: `O(1)`

Only two integer variables are used:

```text
needClose
needOpen
```

So auxiliary space is **O(1)**.

---

## Pattern to Remember

> **Count unmatched parentheses.**

```text
'(' → increase needClose

')' → decrease needClose if possible
      otherwise increase needOpen

Answer = needClose + needOpen
```

This is a simple **Greedy / Counting** approach — no stack is required.
