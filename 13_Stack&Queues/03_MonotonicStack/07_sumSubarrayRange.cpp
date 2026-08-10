➡️ problemLinks -->https://leetcode.com/problems/sum-of-subarray-ranges/  && https://www.geeksforgeeks.org/problems/sum-of-subarray-ranges/1

✅ Optimized Approach --> class Solution {
public:
    vector<int> findNSE(vector<int>& arr ,int n){
        stack<int> st;
        vector<int> NSE(n);
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop(); // arr[st.top], as we have business with indexes 
            NSE[i] = st.empty() ? n : st.top();
            st.push(i); // push index not element as we have business with indexes 
        }
        return NSE;
    }

    vector<int> findPSEE(vector<int>& arr,int n){
        stack<int> st;
        vector<int> PSEE(n);
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            PSEE[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return PSEE;
    }

    vector<int> findNGE(vector<int>& arr ,int n){
        stack<int> st;
        vector<int> NGE(n);
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] <= arr[i]) st.pop(); // arr[st.top], as we have business with indexes 
            NGE[i] = st.empty() ? n : st.top();
            st.push(i); // push index not element as we have business with indexes 
        }
        return NGE;
    }

    vector<int> findPGEE(vector<int>& arr,int n){
        stack<int> st;
        vector<int> PGEE(n);
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] < arr[i]) st.pop();
            PGEE[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return PGEE;
    }

    long long subArrayRanges(vector<int>& arr) {
        int n = arr.size();
        long long sumMin = 0;
        long long sumMax = 0;
        // int mod = (int)(1e9 + 7);
        vector<int> NSE = findNSE(arr,n);
        vector<int> PSEE = findPSEE(arr,n);
        vector<int> NGE = findNGE(arr,n);
        vector<int> PGEE = findPGEE(arr,n);
        
        for(int i = 0; i < n; i++){
            int leftChoices = i - PSEE[i]; 
            int rightChoices = NSE[i] - i;
            int greaterLeft = i - PGEE[i];
            int greaterRight = NGE[i] - i;
            // sum += (leftChoices * rightChoices * arr[i] + 1LL) % mod;
            sumMin = (sumMin + 1LL * leftChoices * rightChoices * arr[i]);
            sumMax = (sumMax + 1LL * greaterLeft * greaterRight * arr[i]); 
        }
        return sumMax - sumMin;
    }
};

Time Complexity : O(n) 

Space Complexity : O(n)

✅ Company Tags -->  