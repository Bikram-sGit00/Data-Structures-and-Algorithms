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




✅ Better Approach --> 

✅ Optimized Approach --> 

✅ Company Tags -->  