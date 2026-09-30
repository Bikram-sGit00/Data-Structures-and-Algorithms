# 678. Valid Parenthesis String

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







