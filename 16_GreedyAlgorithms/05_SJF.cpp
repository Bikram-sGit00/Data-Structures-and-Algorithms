https://www.geeksforgeeks.org/problems/shortest-job-first/1

class Solution {
  public:
    int solve(vector<int>& bt) {
        // SJF: Execute the process with the smallest burst time first.
        // Sorting gives us the order in which processes should run.
        sort(bt.begin(), bt.end());
        
        int workingTime = 0;  // Total CPU time used by previous processes
        int waitingTime = 0;   // Total waiting time of all processes
        
        for(int i = 0; i < bt.size(); i++){
            // Current process waits for all previous processes to finish.
            // So, add the time already spent working.
            waitingTime += workingTime;
            
            // After executing the current process, update total CPU time.
            workingTime += bt[i];
        }
        
        // Average Waiting Time = Total Waiting Time / Number of Processes
        return waitingTime / bt.size();
    }
};

Time Complexity: O(n) + O(n log n) = O(n log n) due to sorting the burst times.
Space Complexity: O(1) as we are tampering the given vector.