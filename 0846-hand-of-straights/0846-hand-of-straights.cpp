class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize){
            return false;
        }
        map<int,int> mp;
        for(int i=0;i<hand.size();i++){
            mp[hand[i]]++;
        }

        for(auto &it:mp){
            if(it.second>0){
                int need=it.second;
                int st=it.first;
                for(int i=st;i<st+groupSize;i++){
                    if(mp[i]<need){
                        return false;
                    }
                    mp[i]-=need;
                }
            }
        }
        return true;
    }
};