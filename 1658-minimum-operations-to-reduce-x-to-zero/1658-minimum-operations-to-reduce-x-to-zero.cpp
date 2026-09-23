class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        nums.push_back(0);
        int n=nums.size();
        vector<int> pre(n+1);
        pre[1]=nums[0];
        for(int i=2;i<n;i++){
            pre[i]=nums[i-1]+pre[i-1];
        }
        int ans=INT_MAX;
        int sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=nums[i];
            int left=x-sum;
            int it=lower_bound(pre.begin(),pre.begin()+i,left)-pre.begin();
            if(pre[it]==left)ans=min(ans, (it)+(n-1-i)) ;
        }
        if(ans==INT_MAX)ans=-1;
        return ans;
    }
};