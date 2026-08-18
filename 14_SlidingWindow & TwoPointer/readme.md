# 🧠 Sliding Window Deep Dive: The Stale `maxFreq` Optimization

> **Problem:** LeetCode 424 - Longest Repeating Character Replacement  
> **Topic:** Two Pointers / Sliding Window  
> **Core Concept:** Why `maxFreq` does not need to be updated when shrinking the window.

---

## 📌 Table of Contents
1. [The Big Question](#1-the-big-question)
2. [Window Validity Formula](#2-window-validity-formula)
3. [What Happens When We Move `l`?](#3-what-happens-when-we-move-l)
4. [The "High-Score Record" Analogy](#4-the-high-score-record-analogy)
5. [Why Stale `maxFreq` Is Harmless](#5-why-stale-maxfreq-is-harmless)
6. [Step-by-Step Code Flow](#6-step-by-step-code-flow)
7. [Code Implementation](#7-code-implementation)
8. [Complexity Comparison](#8-complexity-comparison)
9. [⭐ Key Takeaway](#-key-takeaway)

---

## 1. The Big Question

When shrinking the sliding window (`l++`) and decrementing a character count:

> *"If I remove a character and its count drops, the actual maximum frequency in the current window might drop too. Why don't we recalculate or decrement `maxFreq`?"*

---

## 2. Window Validity Formula

For any window `[l, r]`:
* **Window Length:** `length = r - l + 1`
* **Count of Most Frequent Character:** `maxFreq`
* **Characters to Replace:** `changes = length - maxFreq`

$$\text{Valid Condition: } (r - l + 1) - \text{maxFreq} \le k$$

---

## 3. What Happens When We Move `l`?

Imagine our current window is:

```text
Window:   [ A , A , A , B ]
Counts:   A = 3, B = 1
maxFreq:  3
Length:   4, k = 1
Changes:  4 - 3 = 1  (Valid: 1 <= 1)
```

Now we shrink the window by moving `l` right (removing one `A`):

```text
Window:   [ A , A , B ]
Counts:   A = 2, B = 1
Actual Max Frequency: 2
```

* **Actual max frequency in current window:** `2`
* **Stored `maxFreq` variable:** `3` *(Stale)*

> [!NOTE]
> We intentionally leave `maxFreq = 3` and do not scan the array to decrease it.

---

## 4. The "High-Score Record" Analogy

Think of `maxFreq` as your **all-time high score**, not your current live score:

| Step | Current Window Max | `maxFreq` (Historical Record) | Action |
| :--- | :---: | :---: | :--- |
| `[A, A, A, B]` | 3 | **3** | Record set to 3 |
| Shrink to `[A, A, B]` | 2 | **3** | Record stays 3 (Not erased) |
| Expand to `[A, A, B, A, A]` | 4 | **4** | Record broken! Updated to 4 |

* When adding `r`: we check if we broke the record:  
  `maxFreq = max(maxFreq, freq[s[r]]);`
* When removing `l`: **the record remains unchanged.**

---

## 5. Why Stale `maxFreq` Is Harmless

When actual frequency is `2`, but stored `maxFreq` is `3`:

$$\text{changes} = \text{length} - \text{maxFreq} = 3 - 3 = 0$$

It calculates `0` changes needed instead of `1`.

### Why does this not break the final result?
1. We only care about the **maximum window length** achieved overall.
2. A stale `maxFreq = 3` exists only because we **already achieved a valid window of size $\ge 3 + k$ earlier**.
3. A smaller window (like length 3) cannot produce a new answer larger than what we already found.
4. To find a **new, larger maximum window**, we need a character count to exceed `3`, which will naturally update `maxFreq`.

---

## 6. Step-by-Step Code Flow

```text
[ l ----------------- r ]
```

1. **Expand Right:** `freq[s[r] - 'A']++`
2. **Update Record:** `maxFreq = max(maxFreq, freq[s[r] - 'A'])`
3. **Check Validity:** If `(r - l + 1) - maxFreq > k`, shrink with `freq[s[l] - 'A']--` and `l++`.
4. **Update Answer:** `maxLen = max(maxLen, r - l + 1)`

---

## 7. Code Implementation

### C++
```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int maxFreq = 0;
        int maxLen = 0;
        int l = 0;

        for (int r = 0; r < s.size(); r++) {
            freq[s[r] - 'A']++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']);

            // Shrink from left if window is invalid
            while ((r - l + 1) - maxFreq > k) {
                freq[s[l] - 'A']--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};
```

### Python
```python
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        freq = {}
        max_freq = 0
        max_len = 0
        l = 0

        for r in range(len(s)):
            freq[s[r]] = freq.get(s[r], 0) + 1
            max_freq = max(max_freq, freq[s[r]])

            while (r - l + 1) - max_freq > k:
                freq[s[l]] -= 1
                l += 1

            max_len = max(max_len, r - l + 1)

        return max_len
```

### Java
```java
class Solution {
    public int characterReplacement(String s, int k) {
        int[] freq = new int[26];
        int maxFreq = 0;
        int maxLen = 0;
        int l = 0;

        for (int r = 0; r < s.length(); r++) {
            freq[s.charAt(r) - 'A']++;
            maxFreq = Math.max(maxFreq, freq[s.charAt(r) - 'A']);

            while ((r - l + 1) - maxFreq > k) {
                freq[s.charAt(l) - 'A']--;
                l++;
            }

            maxLen = Math.max(maxLen, r - l + 1);
        }

        return maxLen;
    }
}
```

---

## 8. Complexity Comparison

| Method | Time Complexity | Space Complexity | Explanation |
| :--- | :---: | :---: | :--- |
| **Recalculating `maxFreq` on shrink** | $\mathcal{O}(26 \cdot N)$ | $\mathcal{O}(26) = \mathcal{O}(1)$ | Scans all 26 letters on every `l++` |
| **Keeping stale `maxFreq`** | $\mathcal{O}(N)$ | $\mathcal{O}(26) = \mathcal{O}(1)$ | Pointers move forward at most $N$ times |

---

## ⭐ Key Takeaway

> [!IMPORTANT]
> `freq` array tracks the **exact current window**, but `maxFreq` tracks the **historical peak**. It is intentionally allowed to become stale because a smaller window with stale `maxFreq` can never beat our best answer.