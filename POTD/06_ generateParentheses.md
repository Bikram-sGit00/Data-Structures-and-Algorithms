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

### Brute Force Recursion Tree ($n = 2$)

For $n = 2$, string length is $2 \times 2 = 4$. The brute-force recursion explores every branch of the binary decision tree until length 4:

```text
                                      ""
                           ┌──────────┴──────────┐
                           ↓                     ↓
                          "("                   ")"
                     ┌─────┴─────┐         ┌─────┴─────┐
                     ↓           ↓         ↓           ↓
                   "(("        "()"      ")("         "))"
                  ┌─┴─┐       ┌─┴─┐     ┌─┴─┐       ┌─┴─┐
                  ↓   ↓       ↓   ↓     ↓   ↓       ↓   ↓
                "(((" "(()" "()(" "())" ") ((" ")()" "))(" "))("
                 ↓     ↓      ↓    ↓      ↓    ↓      ↓    ↓
               "((()" "(())" "(() )" "()()" ")(()" ")()" "))( " "))()"
```

#### Detailed Leaf Breakdown ($2^4 = 16$ Candidates)

At depth 4, each leaf is evaluated by `isValid()`:

```text
From "((":  "((((" ✗   "((()" ✗   "(()(" ✗   "(())" ✓
From "()":  "()((" ✗   "()()" ✓   "())(" ✗   "()))" ✗
From ")(":  ")(((" ✗   ")(()" ✗   ")()(" ✗   ")())" ✗
From "))":  "))((" ✗   "))()" ✗   ")))( " ✗   "))))" ✗

Result: Only 2 out of 16 combinations are valid! [ "(())", "()()" ]
```

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

Instead of generating and validating post-hoc, we can prevent invalid choices during recursion by tracking:
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

### Pruned Recursion Tree ($n = 2$)

Notice how pruning cuts off the entire invalid right half of the tree immediately at step 1:

```text
                                  ""
                                  │
                                  ↓ (open < n: 0 < 2)
                                 "("
                        ┌─────────┴─────────┐
      (open < n: 1 < 2) ↓                   ↓ (close < open: 0 < 1)
                      "(("                 "()"
                        │                   │
  (close < open: 0 < 2) ↓                   ↓ (open < n: 1 < 2)
                      "(()"               "()("
                        │                   │
  (close < open: 1 < 2) ↓                   ↓ (close < open: 1 < 2)
                     "(())" ✓             "()()" ✓
```

> **Huge Savings:** The entire right branch starting with `")"` is pruned immediately because `close < open` (`0 < 0`) is false!

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
| **Strings Explored ($n=2$)** | 16 leaves | 2 leaves |
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