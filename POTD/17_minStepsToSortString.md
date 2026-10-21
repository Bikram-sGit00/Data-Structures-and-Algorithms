# Minimum Operations to Sort a String

## Approach — Greedy (Character Comparison)

### Intuition

The goal is to determine the minimum number of operations required to make the string sorted in ascending order.

Instead of simulating operations, we use the positions of the **minimum and maximum characters** to determine the answer.

### Steps

1. **Already sorted:** If the string is sorted, return `0`.
2. **Length equals 2:** If the string has two characters and is not sorted, return `-1`.
3. **One operation:** If the first character is the minimum character or the last character is the maximum character, return `1`.
4. **Check the middle characters:** Find the maximum and minimum characters between the first and last positions.
5. **Three operations:** If the first character is greater than every middle character and the last character is smaller than every middle character, return `3`.
6. **Otherwise:** Return `2`.

## Code (C++)

```cpp
class Solution {
public:
    int minOperations(string s) {
        int n = s.length();

        // If the string is already sorted, no operation is needed.
        if(is_sorted(s.begin(), s.end())) return 0;

        // A string of length 2 cannot be sorted using the allowed operations.
        if(n == 2) return -1;

        // Find the maximum and minimum characters in the entire string.
        char max_char = *max_element(s.begin(), s.end());
        char min_char = *min_element(s.begin(), s.end());

        // If the first character is the minimum or the last is the maximum,
        // the string can be sorted in one operation.
        if(s[0] == min_char || s[n - 1] == max_char) return 1;

        // Find the maximum and minimum characters excluding both endpoints.
        char max_mid = *max_element(s.begin() + 1, s.end() - 1);
        char min_mid = *min_element(s.begin() + 1, s.end() - 1);

        // If the first character is greater than all middle characters
        // and the last character is smaller than all middle characters,
        // three operations are required.
        if(s[0] > max_mid && s[n - 1] < min_mid) return 3;

        // All other unsorted cases require two operations.
        return 2;
    }
};
```

## Complexity Analysis

Let \(n\) be the length of the string.

**Time Complexity: \(O(n)\)**

- `is_sorted()` takes \(O(n)\) in the worst case.
- `max_element()` and `min_element()` each take \(O(n)\).
- The middle-character checks also take \(O(n)\).
- These operations run sequentially, so their complexities add up to \(O(n)\), not \(O(n^2)\).

**Auxiliary Space Complexity: \(O(1)\)**

Only a fixed number of integer and character variables are used. No additional data structure proportional to the input size is created.

## Interview Takeaway

- Check whether the input already satisfies the required condition before doing additional work.
- Use `max_element()` and `min_element()` to reason about character positions without sorting the string.
- Multiple linear scans still result in **\(O(n)\) time complexity**.
- This is a constant-extra-space solution.

**Important:** The correctness of the `1`, `2`, and `3` operation cases depends on the exact operation permitted by the original problem. Be prepared to explain why each condition guarantees the corresponding minimum number of operations.
