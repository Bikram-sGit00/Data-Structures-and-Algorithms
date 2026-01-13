➡️ problemLinks --> https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1?utm_source=copilot.com

✅ Brute Force --> 
 ● First, we will declare an array ‘howMany[]’ of size n-1, to keep track of the number of placed gas stations.
 ● Next, using a loop we will pick k gas stations one at a time.
 ● Then, using another loop, we will find the index 'i' where the distance (arr[i+1] - arr[i]) is the maximum and insert the current gas station between arr[i] and arr[i+1] (i.e. howMany[i]++).
 ● Finally, after placing all the new stations, we will find the distance between two consecutive gas stations. For a particular section, distance = section_length / (number_of_stations_ inserted+1) = (arr[i+1]-arr[i]) / (howMany[i]+1)
Among all the distances, the maximum one will be the answer.

class GasStationSolver {
public:
    // Function to minimize the maximum distance after placing k gas stations
    long double minimizeMaxDistance(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> howMany(n - 1, 0); // howMany[i]: extra stations between arr[i] and arr[i+1]

        // Place k gas stations one at a time
        for (int gasStations = 1; gasStations <= k; gasStations++) {
            long double maxSection = -1;
            int maxInd = -1;

            // Find the segment with the current largest section length
            for (int i = 0; i < n - 1; i++) {
                long double diff = arr[i + 1] - arr[i];
                long double sectionLength = diff / (howMany[i] + 1.0);

                if (sectionLength > maxSection) {
                    maxSection = sectionLength;
                    maxInd = i;
                }
            }

            // Add a gas station in the largest segment
            howMany[maxInd]++;
        }

        // Find the final maximum distance after placing all gas stations
        long double maxAns = -1;
        for (int i = 0; i < n - 1; i++) {
            long double diff = arr[i + 1] - arr[i];
            long double sectionLength = diff / (howMany[i] + 1.0);
            maxAns = max(maxAns, sectionLength);
        }

        return maxAns;
    }
};

// Time Complexity: O(k * n) + O(n) 
// Space Complexity: O(n-1)


✅ Better Approach --> Heap Approach -->
 ● We will use a max-heap (priority queue) to keep track of the largest sections between gas stations.
 ● Initially, we will calculate the distances between each pair of consecutive gas stations and push them into the max-heap.
 ● For each of the k new gas stations, we will extract the largest section from the heap, split it by adding a gas station in the middle, and push the two new sections back into the heap.
 ● After placing all k gas stations, the maximum distance in the heap will be our answer.

class Solution {
  public:
    double minMaxDist(vector<int> &stations, int k) {
        int n = stations.size();
        if (n <= 1) return 0.0;
        vector<int> howMany(n-1,0);
        priority_queue<pair<long double,int>> pq;
        for(int i = 0; i < n-1; i++){
            pq.push({stations[i+1] - stations[i],i});
        }
        for(int gasStations = 1; gasStations <= k; gasStations++){
            auto tp = pq.top();pq.pop();
            int secIndx = tp.second; // which section 
            howMany[secIndx]++;
            long double initDiff = stations[secIndx + 1] - stations[secIndx];
            long double newSecLen = initDiff / (long double) (howMany[secIndx] + 1);
            pq.push({newSecLen,secIndx});
        }
        return pq.top().first;
    }
};

// Time Complexity: O(n long n + k log n)
// Space Complexity: O(n - 1)


✅ Optimized Approach --> 
    ● We will use binary search to find the minimum possible maximum distance.
    ● We will define a helper function that checks if it is possible to place k gas stations such that the maximum distance between any two consecutive gas stations is less than or equal to a given distance.
    ● We will perform binary search on the distance range from 0 to the maximum distance between the first and last gas station.
    ● The answer will be the minimum distance for which the helper function returns true.

// Class that contains methods for optimizing gas station placement
class GasStationOptimizer {
public:
    // Function to calculate number of gas stations required such that
    // no segment exceeds the max allowed distance `dist`
    int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
        int n = arr.size();
        int cnt = 0;

        for (int i = 1; i < n; i++) {
            // Number of stations needed between arr[i-1] and arr[i]
            int numberInBetween = (arr[i] - arr[i - 1]) / dist;

            // If perfectly divisible, reduce one to avoid extra placement
            if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
                numberInBetween--;
            }
            cnt += numberInBetween;
        }
        return cnt;
    }

    // Function to minimize the maximum distance between gas stations
    long double minimiseMaxDistance(vector<int> &arr, int k) {
        int n = arr.size();
        long double low = 0, high = 0;

        // Determine max initial distance between stations
        for (int i = 0; i < n - 1; i++) {
            high = max(high, (long double)(arr[i + 1] - arr[i]));
        }

        long double diff = 1e-6;

        // Binary search to find minimum possible maximum distance
        while (high - low > diff) {
            long double mid = (low + high) / 2.0;
            int cnt = numberOfGasStationsRequired(mid, arr);
            if (cnt > k) low = mid;
            else high = mid;
        }

        return high;
    }
};

// Time Complexity: O(n*log(Len)) + O(n), n = size of the given array, Len = length of the answer space.
// Space Complexity: O(1), as we are using no extra space to solve this problem.

✅ Company Tags -->  