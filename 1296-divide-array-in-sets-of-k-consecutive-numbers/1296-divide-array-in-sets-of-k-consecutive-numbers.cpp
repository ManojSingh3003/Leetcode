class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k){
            return false;
        }
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        for(auto &it:mp){
            if(it.second>0){
                int need=it.second;
                int st=it.first;
                for(int i=st;i<st+k;i++){
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