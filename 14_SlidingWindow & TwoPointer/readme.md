# 🔥 Longest Repeating Character Replacement — `maxFreq` Trick

## Why don't we decrease `maxFreq` when `l` moves?

This is the **tricky part** of the problem.

Suppose our window is:

```text
A A A B

A = 3
B = 1

maxFreq = 3
windowLength = 4
k = 1

Characters that need to be replaced:

windowLength - maxFreq
= 4 - 3
= 1

So the window is valid.

Now l moves

Suppose we remove the first A:

A A B


A = 2
B = 1

Now the actual maximum frequency is 2.

So you might think:

maxFreq = 2;
❌ No!

We keep:

maxFreq = 3;

Even though 3 is no longer the maximum frequency of the current window.

This is called a stale maxFreq.

🧠 What does maxFreq actually mean?

maxFreq does not mean:

"Maximum frequency of the current window."

Instead, it means:

"Highest frequency we have seen so far."

Think of maxFreq as a record.

Highest frequency ever seen = 3

Even if the current frequency drops to 2, the record remains:

maxFreq = 3

Just like:

Highest score ever = 100
Current score = 80

You don't change the highest score to 80.

📌 freqArray vs maxFreq
Variable	Meaning
freqArray	Actual frequency of characters in the current window
maxFreq	Highest frequency seen so far
maxLen	Longest valid window found so far

So:

freqArray[s[l] - 'A']--;

must happen because the current window changed.

But:

maxFreq--;

should NOT happen.

🤔 But isn't the calculation temporarily wrong?

Yes.

Suppose:

Current window:


A A B


Actual max frequency = 2
Stored maxFreq = 3

Actual number of changes needed:

3 - 2 = 1

But using stale maxFreq:

3 - 3 = 0

So we may temporarily consider the window valid when it is not actually valid.

Why doesn't this break the answer?

Because the stale maxFreq = 3 was obtained from an earlier window where a character really had frequency 3.

For example:

A A A B


windowLength = 4
maxFreq = 3


4 - 3 = 1

A window of length 4 was genuinely achievable when maxFreq = 3.

Later, after shrinking:

A A B


windowLength = 3
maxFreq = 3   ← stale

Even if we incorrectly consider this smaller window valid, it cannot give us a new answer larger than the answer we already found.

🔥 The Important Trick

maxFreq only gets updated when r moves:

freqArray[s[r] - 'A']++;


maxFreq = max(maxFreq, freqArray[s[r] - 'A']);

This means:

"Did adding this character create a new frequency record?"

But when l moves:

freqArray[s[l] - 'A']--;
l++;

we do not update maxFreq.

Because:

freqArray → current information
maxFreq   → historical record
❌ Don't do this
freqArray[s[l] - 'A']--;
maxFreq--;   // ❌ WRONG
l++;
✅ Do this
freqArray[s[l] - 'A']--;
l++;

Leave maxFreq unchanged.

💡 Why this gives O(n)

If we wanted maxFreq to always be the exact maximum frequency of the current window, after removing a character we would need to recalculate the maximum.

Instead, we keep the historical maximum:

maxFreq = max(maxFreq, freqArray[s[r] - 'A']);

Therefore:

Time Complexity  = O(n)
Space Complexity = O(26) = O(1)
⭐ One Sentence to Remember

freqArray represents the actual current window, while maxFreq represents the highest frequency we've ever seen and is intentionally allowed to become stale when l moves.

Easy Mental Model
freqArray = "What is happening NOW?"


maxFreq = "What is the BEST frequency I've seen?"

So remember:

// Right pointer enters
freqArray[s[r] - 'A']++;


maxFreq = max(maxFreq, freqArray[s[r] - 'A']);


// Left pointer removes
freqArray[s[l] - 'A']--;
l++;


// ❌ Never decrease maxFreq
// maxFreq--;

