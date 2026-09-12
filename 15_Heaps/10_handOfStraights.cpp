class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize) return false;

        map<int, int> mpp;
        for(auto it : hand){
            mpp[it]++;
        }

        while(!mpp.empty()){
            int currEle = mpp.begin()->first;
            for(int i = 0; i < groupSize; i++){
                if(mpp[currEle + i] == 0) return false;
                mpp[currEle + i]--;
                if(mpp[currEle + i] < 1){
                    mpp.erase(currEle + i);
                }
            }
        }
        return true;
    }
};