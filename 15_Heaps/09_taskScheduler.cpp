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

✅ Optimized Approach --> class Solution { 
public: 
    int leastInterval(vector<char>& tasks, int n) { 
        vector<int> freqArray(26, 0); // all are in uppercase so taken vector instead of map 
        for(auto ch : tasks){ 
            freqArray[ch - 'A']++; // convert char to index: A->0, B->1... and count frequency
        } 

        int time = 0; 
        priority_queue<int> maxHeap; // max heap keeps the task with highest frequency at the top

        for(int i = 0; i < 26; i++){ 
            if(freqArray[i] > 0){ // push into heap if frequency > 0 
                maxHeap.push(freqArray[i]); // only frequency is needed; task identity doesn't matter
            } 
        } 

        while(!maxHeap.empty()){ 
            vector<int> temp; // stores remaining frequencies of tasks used in the current cycle

            // We create a cycle of n+1 slots so the same task gets at least n gaps before repeating
            for(int i = 0; i < n+1; i++){ 
                if(!maxHeap.empty()){ 
                    int freq = maxHeap.top(); 
                    maxHeap.pop(); // take the most frequent task first to reduce future idle time

                    freq--; // use one occurrence of this task in the current cycle
                    temp.push_back(freq); // save its remaining frequency; don't reuse it in this same cycle
                } 
            } 

            // Put unfinished tasks back so they can be selected in the next cycle
            for(auto it : temp){ 
                if(it > 0){ 
                    maxHeap.push(it); 
                } 
            } 

            // If heap is empty, all tasks are finished, so no idle slots are needed at the end, e.g., if heap have [A -> 1] nothing else, so pop this A,
            if(maxHeap.empty()){//                                                                     let answer is something like => A,B,A,_,A - so for this time we also add gap + 1
                time += temp.size(); //                                                                then it will be => A,B,A,_,A,_,_ - so what we will do with the last blank spaces?
            }else{ //                                                                                  that is why we add temp's size, and why temp size ? cause the 
                // Tasks are still remaining, so the complete n+1 cycle is counted,                    last task(means when freq = 1 for that element) wii be in temp, cause temp is
                // including idle slots if there weren't enough different tasks                        storing their frequencies, so why waste gap + 1 slots or time, just add the size
                time += n + 1; 
            } 
        } 

        return time; 
    } 
};

Time Complexity : O(Nlog26) ≈ O(N)

Space Complexity : O(26) ≈ O(1) 

✅ Company Tags -->  
Amazon - asked 10 times in the last 6 months
Google - asked 5 times in the last 6 months
Microsoft - asked 3 times in the last 6 months
Bloomberg - asked 3 times in the last 6 months
Apple - asked 2 times in the last 6 months