➡️ problemLinks --> 

✅ Brute Force --> 
Approach::
For every train, treat its arrival time as a reference point.
Check every other train to see if it has already arrived and has not departed yet.
Such a train needs a platform at the reference train`s arrival time.
The maximum number of trains found at any arrival time is our answer.

Since we check every train against every other train:
Time Complexity: O(N²)
Space Complexity: O(1)


class Solution { 
public: 
    int minPlatform(vector<int>& arrival, vector<int>& dept) { 

        // Try every train's arrival time as a reference point.
        // We will check how many trains are present when this train arrives.
        int minReqPlatform = 0; 
 
        for (int prevTrain = 0; prevTrain < arrival.size(); prevTrain++) { 

            // The reference train itself needs one platform.
            int platform = 1; 
 
            for (int currTrain = 0; currTrain < arrival.size(); currTrain++) { 

                // Ignore the reference train itself.
                // Check if currTrain has already arrived by the time prevTrain arrives
                // and has not departed yet.
                //
                // arrival[currTrain] <= arrival[prevTrain]
                // → currTrain has already arrived.
                //
                // dept[currTrain] >= arrival[prevTrain]
                // → currTrain is still at the station.
                //
                // Therefore, currTrain is occupying a platform at this moment.
                if (currTrain != prevTrain && 
                    arrival[currTrain] <= arrival[prevTrain] && 
                    dept[currTrain] >= arrival[prevTrain]) { 

                    // Another train is occupying a platform,
                    // so we need one more platform.
                    platform++; 
                } 
                 
            } 

            // Store the maximum number of platforms needed
            // at any train's arrival time.
            minReqPlatform = max(minReqPlatform, platform); 
        } 
 
        // Return the maximum number of platforms required
        // so that no train has to wait.
        return minReqPlatform; 
    } 
};


Time Complexity : O(N²)

Space Complexity : O(1)

✅ Better Approach --> 

Time Complexity : 

Space Complexity : 

✅ Optimized Approach --> 

Time Complexity : 

Space Complexity : 

✅ Company Tags -->  Paytm Amazon Microsoft D-E-Shaw Hike Walmart Adobe Google BoomerangCommerce Zillious Atlassian NPCI MorganStanley