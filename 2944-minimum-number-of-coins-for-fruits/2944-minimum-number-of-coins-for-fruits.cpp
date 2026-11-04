class Solution {
public:
    vector<int> memo;

    int dp(int i,int n,vector<int>& prices){
        if(i>=n){
            return 0;
        }
        if(memo[i]!=-1)return memo[i];

        int ans=INT_MAX;
        for(int j=i+1;j<=2*i+2;j++){
            ans = min(ans, dp(j,n,prices));
        }
        return memo[i]=ans+prices[i];
    }

    int minimumCoins(vector<int>& prices) {
        int n=prices.size();

        memo.assign(n+1,-1);

        int ans=dp(0,n,prices);

        return ans;

    }
};
