➡️ problemLinks --> https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

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

✅ Optimized Approach --> 

The core intuition
Think of the two sorted arrays as two events:

Arrival  →  +1 platform
Departure → -1 platform

We always compare the next arrival with the next departure:

if(arr[i] <= dep[j])

If arrival comes first (or at the same time):

+1 platform
Otherwise, a train has already left:
-1 platform


class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {

        // Sort arrivals and departures separately so we can process
        // all trains in chronological order.
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        // i -> points to the next train arrival.
        // j -> points to the earliest train departure.
        int i = 0;
        int j = 0;

        // Current number of platforms being used.
        int platform = 0;

        // Maximum number of platforms needed at any moment.
        int maxi = 0;
        
        // Process every train arrival.
        while(i < arr.size()){

            // If a train arrives before or exactly when the next train departs,
            // both trains need separate platforms at that moment.
            if(arr[i] <= dep[j]){

                // A new train has arrived, so one more platform is needed.
                platform++;
                i++;

            }else{

                // A train has already departed before the next arrival,
                // so its platform becomes free.
                platform--;
                j++;
            }

            // Keep track of the maximum platforms needed at any time.
            maxi = max(maxi, platform);
        }

        // The maximum number of simultaneously occupied platforms is the answer.
        return maxi;
    }
};



Time Complexity : 
 => O(N log N) + O(N log N) + O(2N) 
 => (2 * O(N log N)) + O(2N) 
 => O(2(N log N + N))

Space Complexity : O(1)

✅ Company Tags -->  Paytm Amazon Microsoft D-E-Shaw Hike Walmart Adobe Google BoomerangCommerce Zillious Atlassian NPCI MorganStanley