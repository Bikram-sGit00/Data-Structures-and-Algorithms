➡️ problemLinks --> 

✅ Brute Force -->  
class StockSpanner {
    vector<int> arr;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        arr.push_back(price);
        int cnt = 1;
        for(int i = arr.size() -2; i>=0;i--){
            if(arr[i]<=price) cnt++;
            else break;
        }
        return cnt;
    }
};

Time Complexity : O(n^2)

Space Complexity : O(n)

✅ Better Approach --> 

Time Complexity : 

Space Complexity : 

✅ Optimized Approach --> 

Time Complexity : 

Space Complexity : 

✅ Company Tags -->  