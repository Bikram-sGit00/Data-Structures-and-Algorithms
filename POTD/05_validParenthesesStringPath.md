# Valid Parenthesis Path — Recursion + Memoization

## Problem - [Leetcode](https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/description/?envType=daily-question&envId=2026-09-29)

We are given a grid containing `(` and `)`.

Starting from the top-left cell, we can move only:

* **Down**
* **Right**

We need to check whether there exists a path to the bottom-right such that the characters along the path form a **valid parenthesis sequence**.

A valid sequence must:

* Never have more `)` than `(` at any point.
* Have equal numbers of `(` and `)` at the end.

---

## Approaches

### 1. Recursion / Backtracking

From every cell, we have two choices:

```text
        Current
        /     \
     Down    Right
```

So we recursively try both possible paths.

We maintain:

```cpp
openBracs
```

which represents the number of currently unmatched `(`.

* `(` → `openBracs++`
* `)` → `openBracs--`

If `openBracs` becomes negative, the path is invalid.

At the destination, the path is valid only when:

```cpp
openBracs == 0
```

### Problem with Plain Recursion

Different paths can reach the **same state**:

```text
(i, j, openBracs)
```

If we calculate the same state again, we are repeating the same work.

Therefore, we use **memoization**.

---

# Memoization

## Why Do We Need Memoization?

Our recursive function is:

```cpp
solve(i, j, openBracs, grid)
```

The important changing state is:

```text
i + j + openBracs
```

So one unique DP state is:

```cpp
memo[i][j][openBracs]
```

For example:

```text
memo[3][4][2]
```

means:

> We have already calculated whether a valid path is possible from `(3,4)` when `openBracs = 2`.

If the same state appears again, we don't need to calculate it again.

```cpp
if(memo[i][j][openBracs] != -1)
    return memo[i][j][openBracs];
```

This changes the recursion from repeatedly solving the same states to solving **each state only once**.

---

# Why `memo` Is Initialized With `-1`

Our answer is a `bool`:

```text
true  → 1
false → 0
```

So we need a third value to represent:

```text
"Not calculated yet"
```

We use:

```text
-1 → not calculated
 0 → false
 1 → true
```

Therefore:

```cpp
memset(memo, -1, sizeof(memo));
```

initializes every memo state to `-1`.

### `memset` Syntax

```cpp
memset(array, value, size);
```

For our case:

```cpp
memset(memo, -1, sizeof(memo));
```

means:

> Fill the entire `memo` array with `-1`.

Then we can check:

```cpp
if(memo[i][j][openBracs] != -1)
```

If it is not `-1`, that state has already been calculated.

---

# Important Initial Checks

### 1. Path length must be even

A path from `(0,0)` to `(m-1,n-1)` contains:

```text
m + n - 1
```

cells.

For a valid parenthesis sequence, the number of characters must be even because every `(` needs a matching `)`.

```cpp
if((m + n - 1) % 2 == 1) return false;
```

If the path length is odd, a valid sequence is impossible.

### 2. Starting cell cannot be `)`

The first character cannot close a parenthesis before anything is opened.

```cpp
if(grid[0][0] == ')') return false;
```

### 3. Ending cell cannot be `(`

The final character must be `)` so that the sequence can finish with balance `0`.

```cpp
if(grid[m - 1][n - 1] == '(') return false;
```

---

# Code

```cpp
class Solution {
public:
    int m, n;

    // memo[i][j][openBracs]
    // -1 -> state not calculated
    //  0 -> false
    //  1 -> true
    int memo[101][102][201];

    bool solve(int i, int j, int openBracs, vector<vector<char>>& grid){
        
        // Update the current balance based on the current cell.
        // '(' increases the balance, ')' decreases it.
        openBracs += (grid[i][j] == '(') ? +1 : -1;

        // More ')' than '(' means this path can never become valid.
        if(openBracs < 0) return false;

        // If this state was already calculated, return the stored answer.
        if(memo[i][j][openBracs] != -1){
            return memo[i][j][openBracs];
        }

        // At the destination, the path is valid only if
        // all opened brackets have been closed.
        if(i == m - 1 && j == n - 1){
            return memo[i][j][openBracs] = (openBracs == 0);
        }

        // Move Down
        if(i + 1 < m){
            if(solve(i + 1, j, openBracs, grid)){
                return memo[i][j][openBracs] = true;
            }
        }

        // Move Right
        if(j + 1 < n){
            if(solve(i, j + 1, openBracs, grid)){
                return memo[i][j][openBracs] = true;
            }
        }

        // Neither Down nor Right gives a valid path.
        return memo[i][j][openBracs] = false;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // A valid parenthesis sequence must have even length.
        if((m + n - 1) % 2 == 1) return false;

        // The path must start with '(' and end with ')'.
        if(grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;

        // Initially, every memo state is "not calculated".
        memset(memo, -1, sizeof(memo));

        return solve(0, 0, 0, grid);
    }
};
```

---

# How the Memoization Works

Suppose recursion reaches:

```cpp
solve(2, 3, 4, grid)
```

After solving it, we store:

```cpp
memo[2][3][4] = true;
```

If another path later reaches:

```cpp
solve(2, 3, 4, grid)
```

we immediately return:

```cpp
memo[2][3][4]
```

instead of exploring Down and Right again.

So the basic memoization pattern is:

```cpp
if(memo[state] != -1)
    return memo[state];

return memo[state] = answer;
```

---

# Time Complexity

There are three changing state variables:

```text
i          → m possibilities
j          → n possibilities
openBracs  → at most O(m + n)
```

Therefore, the number of unique states is:

```text
O(m × n × (m + n))
```

Each state does only constant work and checks at most two directions.

### Time:

```text
O(m × n × (m + n))
```

---

# Space Complexity

The memo table stores:

```text
O(m × n × (m + n))
```

states.

The recursion stack can go as deep as the path length:

```text
O(m + n)
```

Therefore:

### Space:

```text
O(m × n × (m + n))
```

for the memo table, plus

```text
O(m + n)
```

for the recursion stack.

Overall:

```text
O(m × n × (m + n))
```

---

## Key Takeaway

The important thing to remember from this problem is:

```text
Recursion
   ↓
Same state can appear again
   ↓
Identify the state: (i, j, openBracs)
   ↓
Store its answer in memo
   ↓
If already calculated, return it
```

The memoization syntax to remember is:

```cpp
if(memo[i][j][openBracs] != -1)
    return memo[i][j][openBracs];

return memo[i][j][openBracs] = answer;
```

And initialization:

```cpp
memset(memo, -1, sizeof(memo));
```

# ✅ Company Tags (2026 Data)

> **`Google`**

