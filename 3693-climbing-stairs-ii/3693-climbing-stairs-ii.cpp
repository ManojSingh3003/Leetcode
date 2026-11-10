class Solution {
public:
    vector<int> memo;

    int dp(int i, int n, vector<int>& costs){
        if(i==n)return 0;

        if(memo[i]!=-1)return memo[i];

        int ans=INT_MAX;
        if(i+1<=n)ans=min(ans, dp(i+1,n,costs) +costs[i]+ (1));
        if(i+2<=n)ans=min(ans, dp(i+2,n,costs) +costs[i+1]+ (4) );
        if(i+3<=n)ans=min(ans, dp(i+3,n,costs) +costs[i+2]+ (9) );

        return memo[i]=ans;
    }

    int climbStairs(int n, vector<int>& costs) {
        memo.assign(n+1,-1);
        int ans=dp(0,n,costs);
        return ans;
    }
};