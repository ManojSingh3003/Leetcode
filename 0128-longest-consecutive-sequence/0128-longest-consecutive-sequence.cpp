class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        if(nums.size()==0)return 0;
        int c=1,ans=0;
        int last=1e9+7;
        for(auto &it:s){
            cout<<it<<" ";
            if(it==last+1)c++;
            else{
                ans=max(ans,c);
                c=1;
            }
            last=it;
        }
        ans=max(ans,c);
        return ans;
    }
};