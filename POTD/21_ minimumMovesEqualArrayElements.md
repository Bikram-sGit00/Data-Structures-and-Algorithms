# 453. Minimum Moves to Equal Array Elements

Problem: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
Difficulty: Medium | Topics: Array, Math | Language: C++

## The question, in my words

I get an array `nums`. In one move I can pick any one element to leave alone and add 1 to all the others (so n-1 elements go up by 1). I need the fewest moves to make every element the same.

Example: `[1,2,3]` -> `[2,3,3]` -> `[3,4,3]` -> `[4,4,4]`, so the answer is 3.

## First thought: brute force

The most direct way to simulate it. Every move, find the biggest element, leave it alone, and add 1 to everything else. Keep going until all elements match.

Leaving the max alone makes sense because it's the one furthest ahead. The others have to catch up to it.

```cpp
int minMoves(vector<int>& nums) {
    int moves = 0;
    while (true) {
        // find the current max and min
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());

        // everyone is equal, we're done
        if (mx == mn) break;

        // skip one max element, +1 to all the rest
        bool skipped = false;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == mx && !skipped) {
                skipped = true;   // leave this one alone
            } else {
                nums[i]++;        // everyone else goes up
            }
        }
        moves++;
    }
    return moves;
}
```

Why it dies: each move costs O(n), and the number of moves can be huge. With values up to 10^9 and n up to 10^5 the answer can reach around 10^14 in the worst case. Time is O(n * moves), which is far too slow. Good for understanding, not for submitting.

## Better: flip the thinking

Adding 1 to n-1 elements changes the gaps between elements in exactly the same way as subtracting 1 from the one element I skipped. Equality only cares about the gaps, not the absolute level. So the move is really "pick one element, subtract 1."

Now the plan is simple. The min element can never be pushed lower than the others need, so every element just has to come down to the minimum. Each element `nums[i]` needs `nums[i] - min` steps to get there. Add those up.

```cpp
int minMoves(vector<int>& nums) {
    // pass 1: find the minimum
    int mini = *min_element(nums.begin(), nums.end());

    // pass 2: how far is each element above the minimum
    int moves = 0;
    for (int x : nums) {
        moves += x - mini;   // steps this element needs to reach the min
    }
    return moves;
}
```

Time O(n), space O(1). This is already a fine interview answer. As a bonus, `x - mini` never gets bigger than the final answer, so it stays inside 32-bit.

## Deriving the formula (the part worth remembering)

Start from the sum of the gaps and take the min out as a common factor, the same way you'd factor in school maths.

Let the elements be a1, a2, ..., an and the minimum be m.

```
moves = (a1 - m) + (a2 - m) + ... + (an - m)
```

Open the brackets and regroup. The a's go together and the m's go together:

```
moves = (a1 + a2 + ... + an) - (m + m + ... + m)
```

The second bracket has m written n times, so it's just `n * m`. The first bracket is the sum of the array:

```
moves = sum - n * m
```

Same thing as "take -m common": `-m` appears once per element, n elements, so `-m * n`.

Check with `[1,2,3]`: sum = 6, n = 3, m = 1, so `6 - 3*1 = 3`. Matches.

### A second way to reach the same formula

If I don't want to rely on the "decrement" trick, I can derive it straight from the original move. Say it takes k moves and every element ends at value x.

- Each move adds 1 to n-1 elements, so the total sum grows by `n - 1` per move. After k moves: `sum + k(n-1)`.
- All n elements equal x at the end, so that total is also `n * x`.
- The minimum element is never the one skipped (we always skip a max), so it got +1 every single move. That means `x = m + k`.

Put these together:

```
sum + k(n-1) = n(m + k)
sum + kn - k = nm + nk
sum - k      = nm
k            = sum - n*m
```

The `kn` terms cancel on both sides and k falls out. Same answer from a different direction, which is reassuring.

## My solution (optimal, one pass)

```cpp
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int mini = INT_MAX;

        for (int i = 0; i < n; i++) {
            sum += nums[i];            // running total of the array
            mini = min(mini, nums[i]); // smallest value seen so far
        }

        // sum - n*min, straight from the derivation above
        return sum - (mini * n);
    }
};
```

Time O(n), space O(1).

One thing to watch: `sum` and `mini * n` can pass the range of `int` on big inputs (n = 10^5, values near 10^9 puts the sum around 10^14). The final answer is guaranteed to fit in 32 bits, and it passes on LeetCode, but the intermediate values overflowing is technically undefined behaviour in C++. Safer version: make `sum` a `long long` and write `(long long)mini * n`, or use the gap-sum loop from the "better" section, which never overflows. Worth mentioning to an interviewer if they ask about edge cases.

## Edge cases to remember

- Single element: answer is 0.
- All elements already equal: answer is 0.
- Negative numbers are fine, the formula doesn't care.

## Complexity at a glance

| Approach | Time | Space |
|---|---|---|
| Brute force simulation | O(n * moves), too slow | O(1) |
| Sum of gaps from min | O(n) | O(1) |
| `sum - n*min` | O(n) | O(1) |

## What I'd say in an interview

Start with the brute force and say it's simulation, then point out it's too slow because moves can be enormous. Then the observation: +1 on n-1 elements is the same as -1 on one element, so everything just comes down to the min. Gap sum first, then compress it to `sum - n*min`. Finish with the overflow note.

## Where it has been asked

I checked a few places and the real data here is thin, so this is what I could actually verify and nothing more.

- Amazon: a candidate report on Hello Interview lists it for a mid-level role, dated mid February 2025. That's the most recent concrete sighting I found.
- Twitter, Morgan Stanley, Adobe: listed on the Naukri Code360 version of the problem. That page was last updated in December 2021, so treat it as older data.
- Meta: there is a Meta-tagged page on Taro, but it gives no date or details I could confirm.

I'm not putting down any frequency percentages. One practice site showed a Google/Microsoft/Facebook breakdown, but it looked auto-generated with no source behind it, so I left it out. Overall it looks like a fairly easy, math-trick medium that shows up now and then rather than a staple, and the lesson it teaches (find the invariant instead of simulating) carries over to other problems.

## Related

- 462. Minimum Moves to Equal Array Elements II (target becomes the median instead of the min)
