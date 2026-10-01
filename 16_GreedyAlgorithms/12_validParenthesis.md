# Valid Parenthesis String - [Leetcode](https://leetcode.com/problems/valid-parenthesis-string/description/)

## Approach 1: Recursion / Backtracking

### Intuition

The only difficult character is `'*'` because it has **3 possible choices**:

```text
'*' → '('
'*' → ')'
'*' → ''
```

So we recursively try all three possibilities and check whether **at least one path** produces a valid parenthesis string.

We maintain `cnt` = number of currently unmatched opening brackets.

### Key Idea

```text
'(' → cnt++
')' → cnt--
'*' → try cnt++, cnt--, and cnt
```

If `cnt` ever becomes negative, that path is invalid because we have more `')'` than `'('`.

---

## Code

```cpp
class Solution {
public:
    bool solver(int indx, int cnt, string s){
        // If closing brackets exceed opening brackets,
        // this path can never become valid.
        if(cnt < 0) return false;

        // Reached the end:
        // valid only when all opening brackets are matched.
        if(indx == s.size()) return (cnt == 0);

        // '(' must act as an opening bracket.
        if(s[indx] == '('){
            return solver(indx + 1, cnt + 1, s);
        }

        // ')' must act as a closing bracket.
        if(s[indx] == ')'){
            return solver(indx + 1, cnt - 1, s);
        }

        // '*' has three possible meanings:
        // '(' -> increase cnt
        // ')' -> decrease cnt
        // ''  -> keep cnt unchanged
        return solver(indx + 1, cnt + 1, s) ||
               solver(indx + 1, cnt - 1, s) ||
               solver(indx + 1, cnt, s);
    }

    bool checkValidString(string s) {
        return solver(0, 0, s);
    }
};
```

### Crucial Lines

```cpp
if(cnt < 0) return false;
```

A prefix cannot have more closing brackets than opening brackets.

```cpp
if(indx == s.size()) return (cnt == 0);
```

At the end, there must be **zero unmatched opening brackets**.

```cpp
return solver(...) || solver(...) || solver(...);
```

For `'*'`, if **any one of the three choices** produces a valid result, return `true`.

### Complexity

There can be 3 choices for every `'*'`:

```text
Time:  O(3^N)
Space: O(N)
```

`O(N)` space comes from the recursion stack.

### Overview

We use backtracking to try all possible meanings of `'*'`.
`cnt` keeps track of unmatched opening brackets, and we return `true` if any possible interpretation makes the string valid.
The problem is that this explores an exponential number of possibilities.

---

# Approach 2: DP — Memoization

### Intuition

The recursive solution can reach the **same state multiple times**.

A state is completely determined by:

```text
(indx, cnt)
```

where:

* `indx` → current position in the string
* `cnt` → current number of unmatched `'('`

If we have already solved the same `(indx, cnt)` state, we don't need to solve it again.

So we store its result in:

```cpp
memo[indx][cnt]
```

This converts repeated recursion into **DP + recursion**.

---

## Code

```cpp
class Solution {
public:
    int memo[101][101];

    bool solver(int indx, int cnt, string s){
        // More ')' than '(' in the current path.
        // This path can never become valid.
        if(cnt < 0) return false;

        // If this state was already calculated,
        // directly return the stored result.
        if(memo[indx][cnt] != -1){
            return memo[indx][cnt];
        }

        // Reached the end:
        // valid only when there are no unmatched '('.
        if(indx == s.size()){
            return memo[indx][cnt] = (cnt == 0);
        }

        // '(' must act as an opening bracket.
        if(s[indx] == '('){
            return memo[indx][cnt] =
                solver(indx + 1, cnt + 1, s);
        }

        // ')' must act as a closing bracket.
        if(s[indx] == ')'){
            return memo[indx][cnt] =
                solver(indx + 1, cnt - 1, s);
        }

        // '*' has three possibilities:
        // '(' -> cnt + 1
        // ')' -> cnt - 1
        // ''  -> cnt
        bool result =
            solver(indx + 1, cnt + 1, s) ||
            solver(indx + 1, cnt - 1, s) ||
            solver(indx + 1, cnt, s);

        // Store the final answer for this state.
        return memo[indx][cnt] = result;
    }

    bool checkValidString(string s) {
        memset(memo, -1, sizeof(memo));

        return solver(0, 0, s);
    }
};
```

### Crucial Lines

```cpp
if(memo[indx][cnt] != -1)
```

If we have already solved this `(indx, cnt)` state, reuse its answer instead of recomputing it.

```cpp
memo[indx][cnt]
```

This represents:

> Can the remaining string be made valid starting from `indx` when `cnt` opening brackets are currently unmatched?

```cpp
bool result =
    solver(indx + 1, cnt + 1, s) ||
    solver(indx + 1, cnt - 1, s) ||
    solver(indx + 1, cnt, s);
```

We still consider all 3 choices for `'*'`, but **each unique state is calculated only once**.

### DP State Count

For `N <= 100`:

```text
indx → 0 ... N
cnt  → 0 ... N
```

So there are at most:

```text
(N + 1) × (N + 1)
```

states.

### Complexity

Each `(indx, cnt)` state is calculated once:

```text
Time:  O(N²)
Space: O(N²)
```

Plus `O(N)` recursion stack, which is dominated by `O(N²)`.

### Overview

We start with the same recursive/backtracking idea, but cache every `(indx, cnt)` state.
This prevents the same state from being explored repeatedly and reduces the exponential recursion to **O(N²)** DP.

---


# Approach 3: Greedy Range — `minOpen` / `maxOpen`

### Intuition

Instead of trying all possibilities of `'*'`, keep a **range of possible unmatched opening brackets**.

* `minOpen` → minimum possible number of open brackets.
* `maxOpen` → maximum possible number of open brackets.

For every character, update both values.
If `maxOpen < 0`, there is no possible way to make the string valid.

At the end, if `minOpen == 0`, at least one valid interpretation exists.

### Why do we need a range?

For `'*'`, we have 3 choices:

```text
'*' → '('   → open count increases
'*' → ')'   → open count decreases
'*' → ''    → open count stays same
```

So instead of exploring all 3 choices, we store only the **minimum and maximum possible open count**.

### Important idea

```text
minOpen = smallest possible unmatched '('
maxOpen = largest possible unmatched '('
```

If `maxOpen < 0`, even the most optimistic interpretation cannot save the string.

---

## Code

```cpp
class Solution { 
public: 
    bool checkValidString(string s) { 
        int minOpen = 0; // minimum possible unmatched '('
        int maxOpen = 0; // maximum possible unmatched '('
 
        for(int i = 0; i < s.size(); i++){ 
            if(s[i] == '('){ 
                // '(' must be an opening bracket.
                // So both minimum and maximum open count increase.
                minOpen++; 
                maxOpen++; 
            }else if(s[i] == ')'){ 
                // ')' decreases the number of unmatched '('.
                // minOpen cannot go below 0 because we can choose a previous '*'
                // as '(' in a valid interpretation.
                minOpen = max(0, minOpen - 1); 
                maxOpen--; 
            }else{ 
                // '*' can act as ')' for the minimum,
                // and as '(' for the maximum.
                minOpen = max(0, minOpen - 1); 
                maxOpen++; 
            } 
 
            // Even the maximum possible open count became negative,
            // so there is definitely an unmatched ')' -> invalid.
            if(maxOpen < 0) return false; 
        } 

        // If the minimum possible open count is 0,
        // at least one interpretation can balance all brackets.
        return (minOpen == 0); 
    } 
};
```

### Crucial lines

```cpp
minOpen = max(0, minOpen - 1);
```

`minOpen` represents the **most balanced/lowest possible** number of open brackets, so `'*'` can be treated as `')'`. We never allow the range below `0`.

```cpp
maxOpen++;
```

For the maximum possibility, `'*'` is treated as `'('`.

```cpp
if(maxOpen < 0) return false;
```

If even the **maximum possible** number of open brackets is negative, there is no possible interpretation that can make the prefix valid.

```cpp
return (minOpen == 0);
```

If the minimum possible count reaches `0`, there is at least one way to interpret the `'*'` characters so that everything balances.

### Complexity

```text
Time:  O(N)
Space: O(1)
```

### Overview

We don't try every possibility of `'*'`.
Instead, we maintain a range `[minOpen, maxOpen]` representing all possible numbers of unmatched `'('`.
This converts the exponential backtracking solution into a single greedy pass.

---

# Approach 4: Two-Pass Greedy

### Intuition

Here we check the string from **both directions**.

### First pass → Left to Right

Treat:

```text
'(' and '*' → potential opening brackets
')'         → closing bracket
```

This makes sure we never have **too many `)`**.

### Second pass → Right to Left

Treat:

```text
')' and '*' → potential closing brackets
'('         → opening bracket
```

This makes sure we never have **too many `(`**.

So:

```text
Left → Right   → checks extra ')'
Right → Left   → checks extra '('
```

If both passes are valid, the string can be balanced.

---

## Code

```cpp
class Solution { 
public: 
    bool checkValidString(string s) { 
        int openBracs = 0; 
        int closeBracs = 0; 
 
        // Left to right:
        // '(' and '*' can help match closing brackets.
        for(int i = 0; i < s.size(); i++){ 
            if(s[i] == '('  || s[i] == '*') openBracs++; 
            else openBracs--; 
 
            // Too many ')' in this prefix.
            // No future character can fix an invalid prefix.
            if(openBracs < 0) return false; 
        } 

        // Right to left:
        // ')' and '*' can help match opening brackets.
        for(int i = s.size()- 1; i >= 0; i--){ 
            if(s[i] == ')'  || s[i] == '*') closeBracs++; 
            else closeBracs--; 
 
            // Too many '(' from this side.
            // No previous character can fix it.
            if(closeBracs < 0) return false; 
        } 

        return true; 
    } 
};
```

### Crucial lines

```cpp
if(s[i] == '(' || s[i] == '*') openBracs++;
```

From the left, we allow `'*'` to behave like `'('` because we want to make sure there aren't too many closing brackets.

```cpp
if(openBracs < 0) return false;
```

If this happens, the current prefix contains more `)` than possible matching `(`.

---

```cpp
if(s[i] == ')' || s[i] == '*') closeBracs++;
```

From the right, we allow `'*'` to behave like `')'` so that we can check whether there are too many opening brackets.

```cpp
if(closeBracs < 0) return false;
```

If this happens, the current suffix has more `(` than possible matching `)`.

### Complexity

```text
Time:  O(N) + O(N) = O(N)
Space: O(1)
```

### Overview

We check the string from both sides instead of deciding what every `'*'` means.
The first pass prevents unmatched `')'`, while the reverse pass prevents unmatched `'('`.
If both directions are valid, the string has a possible valid interpretation.

---

# Quick Comparison

| Approach     |     Time |   Space | Main Idea                           |
| ------------ | -------: | ------: | ----------------------------------- |
| Recursion    | `O(3^N)` |  `O(N)` | Try all `'*'` possibilities         |
| Memoization  |  `O(N²)` | `O(N²)` | Store `(index, openCount)` states   |
| Greedy Range |   `O(N)` |  `O(1)` | Maintain `[minOpen, maxOpen]`       |
| Two Pass     |   `O(N)` |  `O(1)` | Check validity from both directions |

## Final Overview

The main optimization is to **stop explicitly choosing what `'*'` means**.
The range approach keeps all possible open counts in two variables, while the two-pass approach checks the two possible imbalance directions separately.
Both achieve **O(N) time and O(1) extra space**.
