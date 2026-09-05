➡️ problemLinks --> https://leetcode.com/problems/reorganize-string/  &&  https://www.geeksforgeeks.org/problems/rearrange-characters4649/1

✅ Optimized Approach --> class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> maxMaxHeap;
        unordered_map<char, int> mpp;
        for(int i = 0; i < s.size(); i++){
            mpp[s[i]]++;
        }
        for(auto it : mpp){
            maxMaxHeap.push({it.second, it.first}); // in map its {"a",2} but in heap{2,"a"} for prioritizing frequency
        }
        string ans = ""; // for returning answer
        int seat = 0; // seat will tell us what's placed previously
        while(!maxMaxHeap.empty()){
            int freq = maxMaxHeap.top().first;
            char letter = maxMaxHeap.top().second;
            pair<int, char> maxChar = {freq,letter}; // so if max frequent letter is a->3, we pop that 
            maxMaxHeap.pop(); // ↙️
            if(seat == 0 || ans[seat-1] != letter){ // if seat == 0, means have no-one or previous is not same just place
                ans.push_back(letter);
                seat++;
                freq--; // we have add that letter one time into our answer, so reduces that's frequency
                if(freq > 0) maxMaxHeap.push({freq,letter}); // than again push that into heap, a -> 2
                // if(maxMaxHeap.top().first > 0) maxMaxHeap.push(maxChar); // can't do this as they contain old value
            }else{
                // when both letter has same frequency, e.g,let a = b = 1,let previous letter in ans is b, 
                // how i will insert b based on frequency
                if(maxMaxHeap.empty()) return ""; // checking again if heap is empty cause, see ↙️,  we have poped something, e.g, "aa", a will go to answer and then for 2nd "a" heap is empty so not possible answer,return""
                int freq2 = maxMaxHeap.top().first;
                char letter2 = maxMaxHeap.top().second;
                pair<int, char> maxChar2 = {freq2, letter2};
                maxMaxHeap.pop();
                ans.push_back(letter2);//in "if" we know the element was same but now we're doing for next element, and definitely it will not be same so just insert
                seat++;
                freq2--;
                if(freq > 0) maxMaxHeap.push({freq, letter}); // update frequency
                if(freq2 > 0) maxMaxHeap.push({freq2, letter2}); // don't forget that we popped 2 elements,↙️
            }
        }
        return ans;
    }
};

Time Complexity : O(n log n)
- Counting frequencies: O(n)
- Pushing characters into the heap: O(k log k)
- Each character insertion/pop-push operation: O(log k)
- Total for n characters: O(n log k)

Where k = number of distinct characters.
Since k ≤ n, the worst case is:
==> O(n log n)

Space Complexity : O(n)
- unordered_map → O(k) // k = number of unique characters
- priority_queue → O(k) 
- ans → O(n)

✅ Company Tags -->  Amazon - asked 21 times in the last 6 months
Google - asked 5 times in the last 6 months
DE Shaw - asked 3 times in the last 6 months
Tesla - asked 3 times in the last 6 months
Meta - asked 2 times in the last 6 months
Bloomberg - asked 2 times in the last 6 months