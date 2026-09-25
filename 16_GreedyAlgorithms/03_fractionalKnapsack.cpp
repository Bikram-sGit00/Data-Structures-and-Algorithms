➡️ problemLinks --> https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

✅ Optimized Approach --> class Solution {
    struct cmp{
        bool operator()(pair<int, int> &a, pair<int, int> &b){
           return (double)a.first/ a.second > (double)b.first/ b.second; 
        }
    };
    
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        
        vector<pair<int, int>> items;
        for(int i = 0; i < val.size(); i++){  // creating pairs e.g, [60, 10]
            items.push_back({val[i], wt[i]}); //                     [100, 20]
        }
        
        sort(items.begin(), items.end(), cmp()); // sort all values according to their per weight value
        
        double total = 0;
        for(int i = 0; i < items.size(); i++){
            if(items[i].second <= capacity){
                total += items[i].first;
                capacity -= items[i].second;
            }else{ // means current weight is more than capacity so take fractional 
                total += (double)items[i].first/ items[i].second* capacity;
                break; // capacity was not enough already, so we have taken fractional, now nothing left so break
            }
        }
        return total;
    }
};


Time Complexity : (n) + O(nlogn) + O(n) = O(nlogn)  // n for creating pairs, nlogn for sorting, n for traversing the array

Space Complexity : O(n)  // for storing the pairs

✅ Company Tags -->  Microsoft