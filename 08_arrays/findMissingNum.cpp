// Leetcode: https://leetcode.com/problems/missing-number/

//Brute force --> do a linear search for each number from 1 to n using two loops
//Time complexity: O(n^2)
//Space complexity: O(1)

//Better approach --> use a hash table to store the numbers from 1 to n and check for each number if it is present in the hash table or not
//Time complexity: O(2n)
//Space complexity: O(n)

//Optimal approach using summation formula --> the sum of the first n natural numbers is n*(n+1)/2. We can calculate the sum of the first n natural numbers and subtract the sum of the array from it to get the missing number
//  int sum = 0;
//  int n = nums.size();
//     for(int i = 0; i < n; i++){
//         sum += nums[i];
//     }
//     int total = (n * (n + 1)) / 2;
//     return total - sum;
//time complexity: O(n)
//Space complexity: O(1)

//Most optimal approach using XOR --> the XOR of a number with itself is 0 and the XOR of a number with 0 is the number itself. So we can use this property to find the missing number. We can XOR all the numbers from 0 to n and then XOR the result with all the numbers in the array. The result will be the missing number
class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int N = nums.size();  // The array contains N elements, numbers range from [0, N]
            int xor1 = 0;
            int xor2 = 0;
    
            // XOR all indices from 0 to N
            for(int i = 0; i < N; i++) {
                xor1 ^= i;        // XOR of indices
                xor2 ^= nums[i];  // XOR of numbers in array
            }
    
            // Finally, XOR the last index (N) as well
            xor1 ^= N;
    
            return xor1 ^ xor2;  // The missing number
        }
    };
//Time complexity: O(n)
//Space complexity: O(1)

//this approach is better than the summation formula approach because it does not require any additional space and it does not require any arithmetic operations which can cause overflow for large numbers. It also works for negative numbers and non-consecutive numbers.
//The XOR approach is also faster than the summation formula approach because it only requires a single pass through the array and a few XOR operations, while the summation formula approach requires two passes through the array and a few arithmetic operations.

