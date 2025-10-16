➡️ problemLinks --> https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1

✅ Optimized Approach --> int sqrt(int mid ,int n,int m){
    long long ans = 1;
    for(int i = 1; i <= n;i++){
        ans *= mid;
        if(ans > m) return 2;
    }
    if(ans == m ) return 1;
    return 0;
}

class Solution {
  public:
    int nthRoot(int n, int m) {
        int low = 0;
        int high = m;
        while(low <= high){
            int mid = (low+high)/2;
            int midN=sqrt(mid,n,m);
            if(midN == 1) return mid;
            else if(midN == 0) low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
};

// Time Complexity --> O(n * log m)
// Space Complexity --> O(1)

✅ Company Tags -->  Directi Accenture