# 2333. Minimum Sum of Squared Difference

**LeetCode:** [2333. Minimum Sum of Squared Difference](https://leetcode.com/problems/minimum-sum-of-squared-difference/)

## Problem Overview

Given two arrays, `nums1` and `nums2`, we can perform at most `k1 + k2` operations. In each operation, we can increase or decrease an element of either array by `1`.

Our goal is to minimize:

\[
\sum_{i=0}^{n-1} (nums1[i]-nums2[i])^2
\]

**Key observation:** Always reduce the largest absolute difference first. A larger difference contributes more to the answer, so reducing it gives the greatest benefit.

---

## Visual Intuition

Suppose the absolute differences are:

```text
Differences = [3, 3, 3]
Operations  = 4
```

Each operation reduces one difference by `1`.

**Initial differences**

```text
3² + 3² + 3² = 27
```

**After 3 operations**

```text
[3, 3, 3] → [2, 2, 2]
```

**After 1 more operation**

```text
[2, 2, 2] → [1, 2, 2]
```

Final answer:

\[
1^2+2^2+2^2=\boxed{9}
\]

We can solve this using a max heap or optimize it further using a frequency array.

---

## Approach 1: Max Heap (Straightforward Greedy)

### Intuition

A max heap always gives us the largest difference at the top.

1. Calculate all absolute differences and insert them into a max heap.
2. Extract the largest difference.
3. Reduce it by `1` and insert the updated difference back if it is greater than zero.
4. Repeat until all operations are used or every difference becomes zero.
5. Calculate the sum of squared differences.

### Visual

```text
Max Heap

       3
      / \
     3   2

       ↓ Reduce largest difference

       2
      / \
     3   2

Repeat...
```

The heap automatically keeps the largest difference accessible after every operation.

### C++ Code

```cpp
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        int k = k1 + k2;

        priority_queue<int> maxHeap;
        long long totalDiff = 0;

        // Calculate absolute differences and their total sum.
        for(int i = 0; i < n; i++){
            int diff = abs(nums1[i] - nums2[i]);

            maxHeap.push(diff);
            totalDiff += diff;
        }

        // If enough operations can make every difference zero,
        // the minimum possible answer is zero.
        if(k >= totalDiff) return 0;

        // Repeatedly reduce the largest difference.
        while(k > 0 && maxHeap.top() > 0){
            int currDiff = maxHeap.top();
            maxHeap.pop();

            currDiff--;       // Reduce the largest difference by 1.
            maxHeap.push(currDiff);

            k--;
        }

        long long result = 0;

        // Calculate the sum of squared differences.
        while(!maxHeap.empty()){
            long long diff = maxHeap.top();
            maxHeap.pop();

            result += diff * diff;
        }

        return result;
    }
};
```

### Complexity

- **Time:** \(O(n+k\log n)\), where \(k=k1+k2\).
- **Space:** \(O(n)\) for the max heap.

**Limitation:** This approach can be too slow when the number of operations is very large because each operation requires heap updates.

---

## Approach 2: Frequency Array (Optimized)

### Intuition

Instead of storing every difference separately, we store how many times each difference occurs.

For example:

```text
Differences = [3, 3, 2, 1, 3]

Frequency array:

Difference 0 → 0
Difference 1 → 1
Difference 2 → 1
Difference 3 → 3
```

`diffArray[i]` represents the number of elements whose absolute difference is exactly `i`.

### Key Observation

If a difference is `3`, reducing it by `1` moves it from bucket `3` to bucket `2`.

```text
Before:

Difference 3:  ● ● ●
Difference 2:  ●
Difference 1:  ●

             Reduce all 3s

After:

Difference 3:  -
Difference 2:  ● ● ● ●
Difference 1:  ●
```

Instead of processing each element separately, we can move multiple elements between buckets in a single step.

### Steps

1. Find the maximum absolute difference, `maxDiff`.
2. Create a frequency array of size `maxDiff + 1`.
3. Count how many times each difference occurs.
4. Start from `maxDiff` and move toward `1`, always reducing the largest remaining differences first.
5. Move as many elements as possible in one step, limited by both the current frequency and remaining operations.
6. Calculate the sum of squared differences using the final frequencies.

### C++ Code

```cpp
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        int maxDiff = 0;

        // Find the maximum absolute difference.
        for(int i = 0; i < nums1.size(); i++){
            int diff = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diff);
        }

        // diffArray[i] stores the frequency of difference i.
        // +1 is needed because the maximum difference is also an index.
        vector<int> diffArray(maxDiff + 1, 0);

        // Count the frequency of every absolute difference.
        for(int i = 0; i < nums1.size(); i++){
            int diff = abs(nums1[i] - nums2[i]);
            diffArray[diff]++;
        }

        int k = k1 + k2;

        // Reduce the largest differences first.
        for(int currDiff = maxDiff; currDiff > 0 && k > 0; currDiff--){

            // Reduce as many differences as possible in this bucket.
            int operationCnt = min(diffArray[currDiff], k);

            // Move these elements from currDiff to currDiff - 1.
            diffArray[currDiff] -= operationCnt;
            diffArray[currDiff - 1] += operationCnt;

            // Update the remaining number of operations.
            k -= operationCnt;
        }

        long long result = 0;

        // Calculate frequency × squared difference for every bucket.
        for(long long i = 0; i <= maxDiff; i++){
            result += 1LL * diffArray[i] * i * i;
        }

        return result;
    }
};
```

### Complexity

Let `n` be the array length and `D` be the maximum absolute difference.

- **Time:** \(O(n+D)\)
- **Space:** \(O(D)\) for the frequency array.

---

## Final Comparison

| Feature | Max Heap | Frequency Array |
|---|---|---|
| Main idea | Repeatedly reduce the largest difference | Process difference frequencies from largest to smallest |
| Time complexity | \(O(n+k\log n)\) | \(O(n+D)\) |
| Extra space | \(O(n)\) | \(O(D)\) |
| Best use | Understanding the greedy strategy | Efficient solution when operations are large |

## Interview Takeaway

**Pattern:** Greedy + Frequency Counting

Whenever you need to minimize a sum of squared differences with a limited number of unit operations:

- Reduce the largest difference first.
- Use a max heap when you need to repeatedly access the largest value.
- If the values are bounded integers, consider a frequency array to process multiple equal values together.

The frequency-array solution is more efficient because it processes entire groups of equal differences instead of performing a heap operation for every individual reduction.