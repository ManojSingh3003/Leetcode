class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> s;
        s[0]=1;
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(i>0)nums[i]+=nums[i-1];
            
            int x=nums[i]-k;
            if(s.count(x)){
                ans+=s[x];
            }
            s[nums[i]]++;
        }
        
        return ans;
    }
};