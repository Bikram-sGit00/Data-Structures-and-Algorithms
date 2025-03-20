https://www.naukri.com/code360/problems/maximum-frequency-number_920319?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
int maximumFrequency(vector<int> &arr, int n)
{
   unordered_map<int,int>count;
   int maxFreq=0;
   int maxAns=0;
   for(int i=0;i<arr.size();i++){
       count[arr[i]]++;
       maxFreq=max(maxFreq,count[arr[i]]);
   }

   for(int i=0;i<arr.size();i++){
       if(maxFreq==count[arr[i]]){
           maxAns=arr[i];
           break;
       }
   }
   return maxAns;
}

