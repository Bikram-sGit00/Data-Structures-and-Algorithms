➡️ problemLinks --> https://leetcode.com/problems/task-scheduler/  &&  https://www.geeksforgeeks.org/problems/task-scheduler/1

✅ Better Approach --> In this approach we're using a maxHeap to store the frequency of tasks and a map to keep track of the next eligible seat for each task. We iterate through the tasks, placing them in the next available seat while respecting the gap constraint. If a task cannot be placed, it is stored in a pending list and pushed back into the heap for future consideration.
class Solution {
public:
    int leastInterval(vector<char>& tasks, int gap) {
        priority_queue<pair<int, char>> maxHeap;
        unordered_map<char, int> freq;
        unordered_map<char, int> nextEligibleSeat;
        for(auto it : tasks){
            freq[it]++; // count frequency for every element 
            nextEligibleSeat[it] = 1; // anyone can seat in 1st seat
        }
        for(auto it : freq){ // pushing into heap
            maxHeap.push({it.second, it.first});
        }
        int seat = 1;
        while(!maxHeap.empty()){
            vector<pair<int, char>> pendingEle; //if we unable to place anyone, we can't loose them so store them into vector 
            while(!maxHeap.empty()){ // this while is for keep checking
                pair<int, char> currEle = maxHeap.top();
                maxHeap.pop();
                int eleFreq = currEle.first;
                int ele = currEle.second;
                if(seat >= nextEligibleSeat[ele]){// checking if current seat is greater than the previous seat of current Element
                    if(eleFreq > 1){ 
                        maxHeap.push({eleFreq - 1, ele}); // means element is still left so push again into heap
                        nextEligibleSeat[ele] = seat + gap + 1;
                    }
                    break; // if placed so placed, otherwise if we can't place break.
                }else{
                    pendingEle.push_back(currEle); // those who are not placed but are pulled for checking out of maxHeap
                }
            }
            for(int i = 0; i < pendingEle.size(); i++){ // push leftovers back into the heap
                maxHeap.push(pendingEle[i]);
            }
            seat++; 
            
        }
        return seat - 1; // seat is incremented once after the last task is placed, so remove that extra increment
    }
};

Time Complexity : O(n log k)

Space Complexity : O(k) where k is the number of unique tasks.

✅ Optimized Approach --> 

Time Complexity : 

Space Complexity : 

✅ Company Tags -->  
Amazon - asked 10 times in the last 6 months
Google - asked 5 times in the last 6 months
Microsoft - asked 3 times in the last 6 months
Bloomberg - asked 3 times in the last 6 months
Apple - asked 2 times in the last 6 months