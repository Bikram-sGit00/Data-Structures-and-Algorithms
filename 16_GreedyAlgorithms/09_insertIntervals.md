# Insert Interval 

## Problem Overview - [Leetcode](https://leetcode.com/problems/insert-interval/) [GFG](https://www.geeksforgeeks.org/problems/insert-interval-1666733333/1)

We are given a list of **non-overlapping intervals sorted by starting time**, and one `newInterval`.

We have to insert `newInterval` at the correct position.

If `newInterval` **overlaps or touches** any existing interval, we **merge them into one bigger interval**.

### Main Rule

> **If two intervals collide/overlap OR their endpoints touch → merge them into one interval.**

Example:

```text
[1, 6] + [6, 8] → [1, 8]
```

Because they touch at `6`.

But:

```text
[1, 5]    [6, 8]
```

There is a gap, so they stay separate.

---

# Main Idea

We divide all existing intervals into **3 parts**:

```text
LEFT PART          MIDDLE PART             RIGHT PART

No collision       Collision / Merge       No collision
    ↓                     ↓                     ↓
[1,2] [3,4]       [5,7] [6,9]             [12,15]
                         ↑
                    newInterval
```

So we process the intervals in 3 stages:

1. **First `while` → put completely-left intervals into `result`.**
2. **Second `while` → merge all intervals that collide with `newInterval`.**
3. **Third `while` → put remaining right-side intervals into `result`.**

---

# 1️⃣ First `while` — Completely Before New Interval

```cpp
while(i < intervals.size() && intervals[i][1] < newInterval[0]){
    result.push_back({intervals[i][0], intervals[i][1]});
    i++;
}
```

### What are we checking?

```cpp
intervals[i][1] < newInterval[0]
```

Means:

> **Does the existing interval END before the new interval STARTS?**

If yes, there is a **clear gap**, so there is no collision.

### Example

```text
Existing:   [1, 3]
New:                 [5, 8]
```

Check:

```text
existing end = 3
new start    = 5

3 < 5 → true
```

So `[1,3]` is completely before the new interval.

We can safely put it into `result`.

```text
result = [[1,3]]
```

---

## Why `<` and NOT `<=`?

This is VERY important.

Suppose:

```text
Existing: [1, 6]
New:         [6, 8]
```

Check:

```text
6 < 6 → false
```

So it does **not** go into the first loop.

Why?

Because the intervals are touching:

```text
[1------6]
         [6------8]
```

They must be merged.

Therefore:

```cpp
intervals[i][1] < newInterval[0]
```

means:

> **Only move to the left part when there is a real gap.**

### Remember:

```text
end < newStart
      ↓
CLEAR GAP → don't merge
```

```text
end == newStart
      ↓
TOUCHING → merge
```

---

# 2️⃣ Second `while` — Collision / Merge Part

```cpp
while(i < intervals.size() && intervals[i][0] <= newInterval[1]){
    newInterval[0] = min(newInterval[0], intervals[i][0]); 
    newInterval[1] = max(newInterval[1], intervals[i][1]);
    i++;
}
```

This is the **most important part**.

### What are we checking?

```cpp
intervals[i][0] <= newInterval[1]
```

Means:

> **Does the existing interval START before the current new interval ENDS?**

If yes, they can overlap/touch, so we merge them.

---

## Example 1 — Normal Overlap

```text
Existing:   [1, 6]
New:            [5, 8]
```

First loop:

```text
6 < 5 → false
```

So `[1,6]` is not completely before `[5,8]`.

Now second loop:

```text
existing start = 1
new end        = 8

1 <= 8 → true
```

Collision → merge.

```cpp
newInterval[0] = min(5, 1); // 1
newInterval[1] = max(8, 6); // 8
```

Result:

```text
[1,8]
```

---

## Example 2 — Touching Intervals

```text
Existing: [1, 6]
New:         [6, 8]
```

First loop:

```text
6 < 6 → false
```

Second loop:

```text
1 <= 8 → true
```

So they merge:

```text
[1,6] + [6,8] → [1,8]
```

---

# Why Does the Second Condition Work?

Imagine:

```text
Existing:       [6, 10]
New:         [5, 7]
```

The existing interval starts at `6`.

The new interval ends at `7`.

Check:

```text
6 <= 7 → true
```

So there is an overlap:

```text
New:       [5------7]
Existing:      [6---------10]
                  ↑
               overlap
```

Therefore, merge them.

---

# 🔄 The New Interval Can Keep Growing

This is an important detail.

Suppose:

```text
New:       [5, 7]

Existing:     [6, 10]
                  ↓
              [6,10]
```

After merging:

```text
newInterval = [5,10]
```

Now suppose the next interval is:

```text
[9,12]
```

We check it against the **updated** interval:

```text
[5---------10]
       [9---------12]
```

It overlaps again.

So:

```text
newInterval = [5,12]
```

This is why we keep updating:

```cpp
newInterval[0] = min(newInterval[0], intervals[i][0]);
newInterval[1] = max(newInterval[1], intervals[i][1]);
```

We are basically creating one large merged interval.

---

# 3️⃣ Add the Merged Interval

After the second loop finishes:

```cpp
result.push_back({newInterval[0], newInterval[1]});
```

At this point, `newInterval` contains the **entire merged interval**.

Example:

```text
Original new interval: [5,7]

After merging:
[5,7] + [6,10] + [9,12]

Final:
[5,12]
```

So we add:

```text
[5,12]
```

to the answer.

---

# 4️⃣ Third `while` — Completely After

```cpp
while(i < intervals.size()){
    result.push_back({intervals[i][0], intervals[i][1]});
    i++;
}
```

The second loop has stopped because the remaining intervals are now completely after the merged interval.

Example:

```text
Merged interval: [1,8]

Remaining:
[10,12]
[15,20]
```

There is no need to check anything anymore.

Just copy them into `result`.

---

# The Two Conditions You MUST Remember

### First `while`

```cpp
intervals[i][1] < newInterval[0]
```

Read it as:

> **Existing END < New START**

There is a clear gap.

```text
[1,4]      [6,8]
    ↑          ↑
   end        start

4 < 6 → true
```

➡️ **Definitely no collision → put in left part.**

---

### Second `while`

```cpp
intervals[i][0] <= newInterval[1]
```

Read it as:

> **Existing START <= New END**

The existing interval starts before the new interval has finished.

```text
[5------8]
    [7---------10]
     ↑
 existing start

7 <= 8 → true
```

➡️ **Collision/touching → merge.**

---

# 

Think of the new interval as a **person standing in the middle**.

```text
LEFT              NEW               RIGHT

[1,3] [4,5]       [6,8]              [12,15]
  ↓                  ↓                   ↓
copy directly      merge               copy directly
```

### LEFT:

```cpp
existing_end < new_start
```

> "You are completely behind me → go to result."

### MIDDLE:

```cpp
existing_start <= new_end
```

> "You reach into me → merge with me."

### RIGHT:

> "You are completely after me → just copy the rest."

---

# Code 

```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) { 
        vector<vector<int>> result;
        int i = 0;

        // LEFT: intervals completely before newInterval → no collision
        while(i < intervals.size() && intervals[i][1] < newInterval[0]){
            result.push_back({intervals[i][0], intervals[i][1]});
            i++;
        }

        // MIDDLE: intervals that collide/touch → keep merging into newInterval
        while(i < intervals.size() && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[i][0]); 
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        // Add the final merged interval
        result.push_back({newInterval[0], newInterval[1]});

        // RIGHT: remaining intervals are completely after → copy directly
        while(i < intervals.size()){
            result.push_back({intervals[i][0], intervals[i][1]});
            i++;
        }

        return result;
    }
};
```

# ✅ Company Tags (2026 Data)

> **`Google`**
> **`Amazon`**
> **`Meta`**
> **`Amazon`**
> **`Microsoft`**

