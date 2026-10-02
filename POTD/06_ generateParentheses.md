# Generate Parentheses — LeetCode 22

## Problem Description

Given `n` pairs of parentheses, write a function to generate all combinations of **well-formed parentheses**.

### Example

For `n = 3`:

```text
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
```

---

## 1. Brute Force — Generate Everything → Validate

### Intuition

For every position in the string, we have 2 choices:
1. Add `'('`
2. Add `')'`

A valid combination contains exactly $2n$ characters ($n$ opening brackets and $n$ closing brackets).

The brute-force approach generates every possible string of length $2n$ ($2^{2n}$ total combinations) and checks whether each string is valid using `isValid()`.

### Backtracking Pattern

At every recursive call:

```text
Try '('
   ↓
Explore completely
   ↓
Remove '(' (Backtrack)
   ↓
Try ')'
   ↓
Explore completely
   ↓
Remove ')' (Backtrack)
```

**Backtracking philosophy:**
> Try one choice $\rightarrow$ completely explore it $\rightarrow$ undo it $\rightarrow$ try the next choice.

### C++ Code

```cpp
class Solution {
public:
    vector<string> result;

    // Checks whether the generated parenthesis string is valid.
    bool isValid(const string &s) {
        int cnt = 0;

        for (char c : s) {
            // '(' increases unmatched opening brackets.
            if (c == '(') {
                cnt++;
            } 
            // ')' closes one opening bracket.
            else {
                cnt--;
            }

            // If closing brackets exceed opening brackets at any point, it's invalid.
            if (cnt < 0) return false;
        }

        // For a valid string, all opening brackets must be closed.
        return (cnt == 0); 
    }

    void solver(string &curr, int n) {
        // Base case: A complete string contains exactly 2 * n characters.
        if (curr.length() == 2 * n) {
            if (isValid(curr)) {
                result.push_back(curr);
            }
            return;
        }

        // Choice 1: Add '('
        curr.push_back('(');
        solver(curr, n);
        curr.pop_back(); // Backtrack

        // Choice 2: Add ')'
        curr.push_back(')');
        solver(curr, n);
        curr.pop_back(); // Backtrack
    }

    vector<string> generateParenthesis(int n) {
        string curr = "";
        solver(curr, n);
        return result;
    }
};
```

### Dry-Run Idea ($n = 2$)

Required length: $2 \times n = 4$.

1. The recursion first prioritizes choosing `'('`:
   ```text
   "" → "(" → "((" → "(((" → "((((" (Base case reached: length 4)
   ```
2. Check `isValid("((((")` $\rightarrow$ `false`.
3. Backtrack:
   ```cpp
   curr.pop_back(); // "((((" becomes "((("
   ```
4. Move to Choice 2:
   ```cpp
   curr.push_back(')'); // "(((" becomes "(()"
   ```
5. Recurse down on `"(()"`, and so on.

### Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n \cdot 2^{2n})$
  - There are $2^{2n}$ total combinations of length $2n$.
  - For every generated combination, `isValid()` inspects $2n$ characters: $\mathcal{O}(2n \cdot 2^{2n}) = \mathcal{O}(n \cdot 2^{2n})$.
- **Space Complexity:** $\mathcal{O}(n)$
  - Max recursion depth is $2n$.
  - Auxiliary string `curr` has length $2n$.
  - Auxiliary space = $\mathcal{O}(2n) = \mathcal{O}(n)$ (excluding the result container).

---

## 2. Optimized — Generate Only Valid Possibilities (Pruning)

### Intuition

The brute-force method wastes significant operations generating clearly invalid candidates like:
- `")))"`
- `"(((((("`
- `"())()"`

Instead of generating and validating post-hoc, we can prune invalid branches during recursion by tracking:
- `open`: count of `'('` used so far
- `close`: count of `')'` used so far

### Decision Rules

#### Rule 1: When can we add `'('`?
```cpp
if (open < n)
```
- We are allowed at most $n$ opening brackets.
- As long as `open < n`, we still have opening brackets available to place.

#### Rule 2: When can we add `')'`?
```cpp
if (close < open)
```
- A closing bracket can only be added if there is an unmatched opening bracket already placed.
- If `close == open`, adding `')'` immediately creates an invalid prefix like `")"` or `"())"`.

### Important Observation

Because choices are strictly bound by `open < n` and `close < open`:
- Every string that reaches `curr.length() == 2 * n` is **guaranteed to be well-formed**.
- We never need to call `isValid()`.

### C++ Code

```cpp
class Solution {
public:
    vector<string> result;

    void solver(string &curr, int n, int open, int close) {
        // Base case: Valid combination formed
        if (curr.length() == 2 * n) {
            result.push_back(curr);
            return;
        }

        // Choice 1: Add '(' if we haven't used all n opening brackets
        if (open < n) {
            curr.push_back('(');
            solver(curr, n, open + 1, close);
            curr.pop_back(); // Backtrack
        }

        // Choice 2: Add ')' if unmatched '(' are available
        if (close < open) {
            curr.push_back(')');
            solver(curr, n, open, close + 1);
            curr.pop_back(); // Backtrack
        }
    }

    vector<string> generateParenthesis(int n) {
        string curr = "";
        solver(curr, n, 0, 0);
        return result;
    }
};
```

### Complexity Analysis

- **Time Complexity:** $\mathcal{O}\left(\frac{4^n}{\sqrt{n}}\right) = \mathcal{O}(2n \cdot C_n)$
  - The number of valid parentheses strings of length $2n$ is given by the $n$-th **Catalan number**:
    $$C_n = \frac{1}{n + 1}\binom{2n}{n} \approx \frac{4^n}{n\sqrt{\pi n}}$$
  - Each valid string takes $\mathcal{O}(2n)$ to build and copy into the result.
  - Overall Time Complexity: $\mathcal{O}(2n \cdot C_n) = \mathcal{O}\left(\frac{4^n}{\sqrt{n}}\right)$.
  - This is asymptotically optimal (output-sensitive).
- **Space Complexity:** $\mathcal{O}(n)$
  - Max recursion stack depth: $2n$.
  - Temporary string `curr`: $2n$.
  - Auxiliary space = $\mathcal{O}(2n) = \mathcal{O}(n)$ (excluding output storage).

---

## 3. Comparison & Summary

| Metric | Brute Force | Optimized Backtracking |
| :--- | :--- | :--- |
| **Strategy** | Generate all $2^{2n}$ strings, then validate | Constrain choices during generation |
| **Time Complexity** | $\mathcal{O}(n \cdot 2^{2n})$ | $\mathcal{O}\left(\frac{4^n}{\sqrt{n}}\right) = \mathcal{O}(2n \cdot C_n)$ |
| **Space Complexity** | $\mathcal{O}(n)$ | $\mathcal{O}(n)$ |
| **Strings Checked** | $2^{2n}$ | $C_n$ (Only valid combinations) |
| **Validation Needed?** | Yes (`isValid()`) | No (Guaranteed valid by construction) |

### Mental Model

```text
Brute Force:
Generate every possibility → Check validity at base case → Keep valid ones
Pattern: Generate → Validate

Optimized:
Check condition first → Only explore valid branches → Direct valid results
Pattern: Generate with Constraints (Pruning)
```

### How to Recognize This Pattern in Interviews

When a problem asks to:
1. *Generate all valid combinations / permutations / arrangements*
2. *Construct solutions step-by-step with multiple choices at each step*

Ask yourself:
> **"Can I know a choice is invalid before making the recursive call?"**

- If **Yes**, enforce constraints immediately (`open < n`, `close < open`) to prune the recursion tree.