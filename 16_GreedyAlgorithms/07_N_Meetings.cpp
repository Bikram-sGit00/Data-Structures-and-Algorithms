➡️ problemLinks --> https://www.geeksforgeeks.org/problems/maximum-meetings-in-one-room/1

Overview ::
We are given the start and finish times of multiple meetings and need to attend the maximum number of meetings without overlapping.
A new meeting can be attended only if its start time is strictly greater than the finish time of the previously selected meeting.
To get the maximum number, we use a greedy approach: always choose the meeting that finishes earliest. so we sorted the meetings according to their finish time and then we check if the next meeting can be attended or not. If it can be attended, we add it to our result.

✅ Optimized Approach --> class Solution {
    struct triplet{
        int start, end, indx;
    };
    struct cmp{
        bool operator()(const triplet& a, const triplet& b){
            if(a.end != b.end){
                return a.end < b.end;  // sort in asending order according to ending time
            }
            return a.indx < b.indx;   // if ending time is equal, so according to index
        }
    };
  public:
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        // {startTime, endTime, position} storing everything in this format 
        vector<triplet> meetings;
        for(int i = 0; i < s.size(); i++){ //! ⁡⁢⁢⁡⁣⁢⁢⁡⁢⁣⁢𝘖(𝘯)⁡
            // meetings[i].start = s[i];
            // meetings[i].end = f[i];
            // meetings[i].indx = i + 1;
            meetings.push_back({s[i], f[i], i + 1});
        }
        
        // sort(meetings.begin(), meetings.end(), cmp());
        sort(meetings.begin(), meetings.end(), cmp{}); // can also be written with {}, //! 𝘖(𝘯𝘭𝘰𝘨𝘯)⁡
        
        int lastFinishTime = meetings[0].end; // storing first elements ending time, as that will be performed for sure 
        vector<int> result = {meetings[0].indx}; // have to⁡⁢⁢⁢ return index, so created this vector, which will for sure store the first meeting's index
        
        for(int i = 1; i < meetings.size(); i++){ // start from 2nd meeting         //! 𝘖(𝘯)
            if(meetings[i].start > lastFinishTime ){ // if new meetings`s start time is after previous`s ending then only perform else can't do,skip
                result.push_back(meetings[i].indx);
                lastFinishTime = meetings[i].end; // update 
            }
        }
        sort(result.begin(), result.end()); // they want in sorted order 🥲  //! 𝘖(𝘬 𝘭𝘰𝘨 𝘬)
        return result;
    }
};

Time Complexity : O(n) + O(nlogn) + O(n) + O(klogk) = O(nlogn) where n is the number of meetings and k is the number of meetings that can be attended.

Space Complexity :
- start → n
- end → n
- indx → n

- O(3 x n) = O(3n)

- + O(n) for storing the result vector

- (logn) sorting takes O(logn) auxiliary stack space

overall :: O(3n) + O(n) ≈ O(n)

✅ Company Tags -->  