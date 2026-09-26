➡️ problemLinks --> https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

✅ Brute Force --> class Solution {
  public:
    // Sort jobs by profit in descending order.
    // We try to schedule the highest-profit jobs first.
    struct cmp{
      bool operator()(const pair<int, int>& a, const pair<int, int>& b){
          return a.second > b.second;
      }
    };
    
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        
        vector<pair<int, int>> jobs;
        
        // Store each job as {deadline, profit}.
        for(int i = 0; i < deadline.size(); i++){
            jobs.push_back({deadline[i], profit[i]});
        }
        
        // Highest profit job comes first.
        sort(jobs.begin(), jobs.end(), cmp());
        
        int maxProfit = 0;
        int cnt = 0; // Number of jobs successfully scheduled.
        int maxDeadline = -1; // Maximum deadline -> size of hash array.
        
        // Find the maximum deadline so we know how many time slots
        // are required.
        for(int i = 0; i < jobs.size(); i++){
            maxDeadline = max(maxDeadline, jobs[i].first);
        }
        
        // jobHash[j] tells whether time slot j is already occupied.
        // -1 = empty slot
        //  1 = occupied slot
        vector<int> jobHash(maxDeadline + 1, -1);
        
        // Try to schedule every job, starting with the most profitable.
        for(int i = 0; i < jobs.size(); i++){
            
            // Start from the job's deadline and move backwards.
            // We want the latest possible free slot so earlier slots
            // remain available for jobs with smaller deadlines.
            for(int j = jobs[i].first; j > 0; j--){
                
                if(jobHash[j] == -1){
                    
                    // Found a free slot -> schedule this job.
                    cnt++;
                    maxProfit += jobs[i].second;
                    
                    // Mark this time slot as occupied.
                    jobHash[j] = 1;
                    
                    break;
                }
            }
        }
        
        return {cnt, maxProfit};
    }
};

Time Complexity : O(n log n + n x maxDeadline)

Space Complexity : O(n + maxDeadline)

✅ Company Tags -->  Flipkart Accolite Microsoft NPCI, Google(2021)