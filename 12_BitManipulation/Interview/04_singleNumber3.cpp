➡️ problemLinks --> https://leetcode.com/problems/single-number-iii/description/

✅ Brute Force -->  class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // Step 1: Count how many times each number appears.
        // Using an unordered_map for O(1) average lookup/insert.
        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
        }

        // Step 2: Walk through the map and pick out the two numbers
        // that appear exactly once — those are our answers.
        vector<int> result;
        for(auto& pair : freq){
            if(pair.second == 1){
                result.push_back(pair.first);
            }
        }

        return result;
    }
};

// Time Complexity: O(n log m + m) , where n is the size of input array
// Space Complexity: O(m) , where n is the size of input array

✅ Optimized Approach --> class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // XOR all numbers together.
        // Duplicates cancel out (x ^ x = 0), so what remains is
        // the XOR of the two unique numbers: xorr = a ^ b
        long xorr = 0;
        for(int i = 0; i < nums.size(); i++){
            xorr = xorr ^ nums[i];
        }

        // Isolate the lowest set bit of xorr.
        // Since a != b, xorr != 0, so it has at least one set bit.
        // (xorr & (xorr-1)) clears the lowest set bit,
        // XOR-ing that back with xorr leaves ONLY that lowest set bit.
        // This bit is guaranteed to differ between a and b
        // (if it were the same in both, it would've cancelled out above).
        int rightMost = xorr & (xorr-1) ^ xorr;

        int oneGang = 0;   // will hold XOR of all numbers with rightMost bit set
        int zeroGang = 0;  // will hold XOR of all numbers with rightMost bit unset

        // Split all numbers into two groups based on the rightMost bit.
        // - a and b are guaranteed to land in DIFFERENT groups (that's the whole trick).
        // - Every duplicate pair lands in the SAME group, since a number's bits
        //   don't change between its two occurrences, so they still cancel via XOR.
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] & rightMost){ // or if(nums[i] & rightMost == 1)  
                oneGang = oneGang ^ nums[i];
            } 
            else zeroGang = zeroGang ^ nums[i];
        }

        // After XOR-ing within each group, duplicates have cancelled out,
        // leaving exactly one unique number in each group.
        return {oneGang, zeroGang};
    }
};

// Time Complexity: O(2n) , where n is the size of input array
// Space Complexity: O(1)

✅ Company Tags -->  