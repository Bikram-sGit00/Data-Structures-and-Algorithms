class Solution {
    public:
        void moveZeroes(vector<int>& arr) {
            int n=arr.size();
            int j=0;
            for(int i=0;i<n;i++){
                if(arr[i]==0){
                    j=i;
                    break;
                }
            }
            // if(j==-1) 
            for(int i=j+1;i<n;i++){
                if(arr[i]!=0){
                    if(n>=2 && arr[j]!=0){
                        swap(arr[i],arr[j]);
                    }
                    j++;
                }
            }
        }
    };