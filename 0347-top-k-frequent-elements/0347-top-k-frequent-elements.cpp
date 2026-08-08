class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)mp[nums[i]]++;
        multimap<int,int,greater<int>> mp1;
        for(auto &it:mp){
            mp1.insert({it.second, it.first});
        }
        vector<int> ans;
        int i=0;
        for(auto &it :mp1){
            ans.push_back(it.second);
            i++;
            if(i>=k)break;
        }   
        return ans;
    }
};