# Maximum Nesting Depth of the Parentheses

## Problem Overview - [LeetCode](https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/?envType=daily-question&envId=2026-09-28)  [GFG](https://www.geeksforgeeks.org/problems/maximum-nesting-depth-of-the-parentheses/1)

Given a valid parentheses string `s`, find the **maximum nesting depth** of the parentheses.

The nesting depth means the maximum number of `(` that are open at the same time.

### Example

```text
s = "(1+(2*3)+((8)/4))+1"

Maximum depth = 3
```

Because at one point we have:

```text
(((
```

So the maximum nesting depth is `3`.

---

# Approach 1: Stack

### Idea

Parentheses naturally follow a **stack pattern**:

* When we see `(` → push it into the stack.
* When we see `)` → pop it from the stack.
* The current stack size represents the current nesting depth.
* Keep updating the maximum stack size.

### Pattern

```text
'(' → push → depth increases
')' → pop  → depth decreases
```

The largest stack size reached is the answer.

### Code

```cpp
// if we see parentheses use stack, so tried this approach first
class Solution { 
public: 
    int maxDepth(string s) { 
        stack<char> st; 
        int maxDepth = 0; 
 
        for(int i = 0; i < s.size(); i++){ 
            if(s[i] == '(') st.push(s[i]); 
            else if(s[i] == ')') st.pop(); 
            maxDepth = max(maxDepth, (int)st.size()); // .size() returns size_T type 
        } 
        return maxDepth; 
    } 
};
```

### Why does `st.size()` give the depth?

Suppose:

```text
s = "((()))"
```

As we scan:

```text
( → stack size = 1
( → stack size = 2
( → stack size = 3   ← maximum
) → stack size = 2
) → stack size = 1
) → stack size = 0
```

Therefore:

```text
Maximum depth = 3
```

### Complexity

* **Time:** `O(N)` — we scan the string once.
* **Space:** `O(N)` — in the worst case all characters can be `(` and go into the stack.

---

# Approach 2: Counter — Optimal

## Key Observation

We don't actually need to store the parentheses.

We only care about:

> **How many `(` are currently open?**

So instead of a stack, maintain a counter:

```cpp
openBrac
```

### Rules

```text
'(' → openBrac++
')' → openBrac--
```

After every character:

```cpp
maxDepth = max(maxDepth, openBrac);
```

The largest value of `openBrac` is the maximum nesting depth.

### Code

```cpp
class Solution { 
public: 
    int maxDepth(string s) { 
        int maxDepth = 0; 
        int openBrac = 0; 
        for(int i = 0; i < s.size(); i++){ 
            if(s[i] == '(') openBrac++; 
            else if(s[i] == ')') openBrac--; 
            maxDepth = max(maxDepth, openBrac); 
        } 
        return maxDepth; 
    } 
};
```

### Simple Example

For:

```text
s = "((()))"
```

We maintain only the count:

```text
( → openBrac = 1
( → openBrac = 2
( → openBrac = 3   ← maximum
) → openBrac = 2
) → openBrac = 1
) → openBrac = 0
```

Answer:

```text
3
```

---

# Why Counter Is Better Here?

The stack stores every opening parenthesis:

```text
(
((
(((
```

But we don't actually care **which** parentheses are inside the stack.

We only care about **how many** are currently open.

Therefore:

```text
Stack → stores information we don't need
Counter → stores only the required information
```

So the counter solution reduces the auxiliary space from `O(N)` to `O(1)`.

---

# Stack vs Counter

| Approach |   Time |  Space | Idea                          |
| -------- | -----: | -----: | ----------------------------- |
| Stack    | `O(N)` | `O(N)` | Store every opening `(`       |
| Counter  | `O(N)` | `O(1)` | Only count currently open `(` |

### Recommended Approach

The **counter approach** is the optimal solution for this problem because the stack's only useful information is its size.

---

# How to Recognize This Pattern?

Whenever a problem asks for:

* Parentheses nesting depth
* Current number of open brackets
* Maximum number of simultaneously open parentheses

Think:

```text
'(' → +1
')' → -1
```

If you only need the **depth/count**, a counter is enough.

If you need to actually **store or process the opening elements**, then a stack may be required.

### Memory Trick

```text
Need only depth/count → Counter
Need actual elements/order → Stack
```

---

# Final Takeaway

The stack solution works because the **stack size represents the current nesting depth**.

But we can notice that we never use the actual elements stored in the stack. We only use its size.

So we can replace the stack with one integer:

```cpp
openBrac
```

This gives:

```text
Time  → O(N)
Space → O(1)
```
