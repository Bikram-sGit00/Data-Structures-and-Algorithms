# Count Days Spent Together - [Leetcode](https://leetcode.com/problems/count-days-spent-together/?envType=daily-question&envId=2026-10-24)

**Problem:** LeetCode 2409
**Topic:** Math, Strings, Date Handling
**Difficulty:** Easy

---

## Problem Statement

Alice and Bob are both visiting Rome on separate trips. You get four dates in `"MM-DD"` format:

- `arriveAlice`, `leaveAlice`: Alice's stay
- `arriveBob`, `leaveBob`: Bob's stay

Return the number of days they are in Rome at the same time. Both the arrival and leaving days count. Ignore leap years, so February always has 28 days.

**Example 1**

```
Input:  arriveAlice = "08-15", leaveAlice = "08-18",
        arriveBob   = "08-16", leaveBob   = "08-19"
Output: 3
```

**Example 2**

```
Input:  arriveAlice = "10-01", leaveAlice = "10-31",
        arriveBob   = "11-01", leaveBob   = "12-31"
Output: 0
```

---

## Intuition

Comparing dates like `"08-15"` and `"11-01"` directly is messy because the month and day sit in different places. The trick is to turn every date into a single number: its position in the year (day 1 to day 365). Once everything is just a number, each stay is a plain interval on a number line, and the question becomes "how long is the overlap of two intervals?"

For two intervals `[a1, a2]` and `[b1, b2]`:

```
overlap start = max(a1, b1)     // the later arrival
overlap end   = min(a2, b2)     // the earlier departure
overlap days  = end - start + 1 // +1 because both ends are inclusive
```

If the result is zero or negative, they never met, so the answer is `0`.

---

## Approach

1. Store the number of days in each month.
2. Build a prefix sum array where `continueDateCount[m]` means "total days in the year up to the end of month `m`".
3. Convert a date to a day number: `continueDateCount[month - 1] + day`. We take the previous month's total, then add the day within the current month.
4. Convert all four dates.
5. Find the overlap using the max-of-arrivals and min-of-departures idea.
6. Clamp negatives to `0`.

---

## Code (C++)

```cpp
class Solution {
public:
    // Converts "MM-DD" into the day number of the year (1 to 365)
    int toDays(string s, vector<int>& continueDateCount){
        int month = stoi(s.substr(0, 2)); // chars 0-1 -> "MM"
        int day   = stoi(s.substr(3));    // chars 3-4 -> "DD" (index 2 is the '-')

        // days in all full months before this one + the day in this month
        return continueDateCount[month - 1] + day;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        // 13 slots so that index 1 = January, and index 0 stays 0 as the "before January" base
        vector<int> continueDateCount(13, 0);
        continueDateCount[1] = 31; // January ends on day 31

        for(int i = 2; i <= 12; i++){
            // total up to month i = total up to month i-1 + days in month i
            continueDateCount[i] = continueDateCount[i - 1] + monthDays[i - 1];
        }

        // convert all four dates into day-of-year numbers
        int arrivalAliceDate = toDays(arriveAlice, continueDateCount);
        int leaveAliceDate   = toDays(leaveAlice, continueDateCount);

        int arrivalBobDate   = toDays(arriveBob, continueDateCount);
        int leaveBobDate     = toDays(leaveBob, continueDateCount);

        // overlap = earlier departure - later arrival + 1 (both ends inclusive)
        int ans = min(leaveAliceDate, leaveBobDate) - max(arrivalAliceDate, arrivalBobDate) + 1;

        // negative means the stays never overlap
        return (ans < 0) ? 0 : ans;
    }
};
```

---

## Pen and Paper Dry Run

### Step 1: Build the prefix sum table

Start with `monthDays` and keep a running total.

| Month (i) | Name | Days in month | `continueDateCount[i]` | Working                |
|-----------|------|---------------|------------------------|------------------------|
| 0         | none | -             | 0                      | base value             |
| 1         | Jan  | 31            | 31                     | set manually           |
| 2         | Feb  | 28            | 59                     | 31 + 28                |
| 3         | Mar  | 31            | 90                     | 59 + 31                |
| 4         | Apr  | 30            | 120                    | 90 + 30                |
| 5         | May  | 31            | 151                    | 120 + 31               |
| 6         | Jun  | 30            | 181                    | 151 + 30               |
| 7         | Jul  | 31            | 212                    | 181 + 31               |
| 8         | Aug  | 31            | 243                    | 212 + 31               |
| 9         | Sep  | 30            | 273                    | 243 + 30               |
| 10        | Oct  | 31            | 304                    | 273 + 31               |
| 11        | Nov  | 30            | 334                    | 304 + 30               |
| 12        | Dec  | 31            | 365                    | 334 + 31               |

Sanity check: December ends at 365. Good.

### Step 2: Dry run on Example 1

Input: Alice `08-15` to `08-18`, Bob `08-16` to `08-19`

**Convert each date.** Month 8 means we look at `continueDateCount[7] = 212` (everything up to the end of July).

| Date    | Month | Day | Formula          | Day number |
|---------|-------|-----|------------------|------------|
| `08-15` | 8     | 15  | `cdc[7] + 15` = 212 + 15 | **227** |
| `08-18` | 8     | 18  | 212 + 18         | **230**    |
| `08-16` | 8     | 16  | 212 + 16         | **228**    |
| `08-19` | 8     | 19  | 212 + 19         | **231**    |

**Draw it on a number line:**

```
day:    227  228  229  230  231
Alice:   [----------------]
Bob:          [----------------]
Both:         [-----------]
              228  229  230
```

**Apply the formula:**

```
later arrival   = max(227, 228) = 228
earlier leave   = min(230, 231) = 230
overlap         = 230 - 228 + 1 = 3
```

The answer is `3`, which matches. The days they share are 228, 229 and 230, which are Aug 16, 17 and 18.

### Step 3: Dry run on Example 2 (no overlap)

Input: Alice `10-01` to `10-31`, Bob `11-01` to `12-31`

| Date    | Formula       | Day number |
|---------|---------------|------------|
| `10-01` | `cdc[9] + 1` = 273 + 1   | **274** |
| `10-31` | `cdc[9] + 31` = 273 + 31 | **304** |
| `11-01` | `cdc[10] + 1` = 304 + 1  | **305** |
| `12-31` | `cdc[11] + 31` = 334 + 31| **365** |

```
day:    274 ......... 304  305 ......... 365
Alice:   [-------------]
Bob:                         [-------------]
                         ^ gap, no shared day
```

```
later arrival = max(274, 305) = 305
earlier leave = min(304, 365) = 304
overlap       = 304 - 305 + 1 = 0
```

`ans = 0`, so we return `0`. Alice leaves on Oct 31 and Bob arrives on Nov 1, so they miss each other by one day.

### Step 4: Why the `ans < 0` check matters

Take Alice `01-01` to `01-10` and Bob `02-01` to `02-10`.

```
Alice: 1  to 10
Bob:   32 to 41

later arrival = max(1, 32)  = 32
earlier leave = min(10, 41) = 10
overlap       = 10 - 32 + 1 = -21
```

The raw formula goes negative whenever the gap between the stays is more than one day. Without the clamp we would return `-21`, so we return `0` instead.

---

## Complexity

**Time: O(1)**
The prefix array always has 13 entries and the loop always runs 11 times, no matter what the input is. Parsing a fixed-length 5 character string is also constant. Nothing here scales with input size.

**Space: O(1)**
`monthDays` has 12 entries and `continueDateCount` has 13. Both are fixed size, so the extra memory is constant.

---

## Things Worth Remembering

- **Why 13 slots:** index 0 acts as "zero days before January". This lets `toDays` use `month - 1` for every month with no special case for January.
- **Why `+ 1`:** both the arrival day and the leaving day count, so a one-day stay overlaps for 1 day, not 0.
- **Why `substr(3)`:** in `"MM-DD"` the dash sits at index 2, so the day starts at index 3 and runs to the end.
- **No leap years:** the problem says to ignore them, so February is fixed at 28.
- **Common mistake:** using `continueDateCount[month]` instead of `[month - 1]` in `toDays`. That counts the current month's full length and then adds the day again.
- **Pattern to reuse:** whenever a problem asks for the overlap of two ranges, think `max(starts)` and `min(ends)`, then clamp at zero.

---

## Possible Improvement

The prefix array gets rebuilt on every call. Since it never changes, it could be declared once as a `static const` array of 13 values and reused. It is still O(1) either way, but it is slightly cleaner.