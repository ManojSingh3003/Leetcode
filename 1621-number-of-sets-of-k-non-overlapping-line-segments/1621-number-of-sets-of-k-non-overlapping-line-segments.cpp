class Solution {
const int mod=1e9+7;
vector<vector<int>> memo;
private:
    int dp(int i,int k,int& n){
        if(i==n){
            if(k==0)return 1;
            else return 0;
        }
        if(k==0)return 1;

        if(memo[i][k]!=-1)return memo[i][k];

        int ans=dp(i+1,k,n);
    
        for(int j=i+1;j<n;j++){
            ans = (ans + dp(j,k-1,n) )%mod;
            if(n-j-1 < k-1 ) break;
        }
        return memo[i][k]=ans;
    }
public:
    int numberOfSets(int n, int k) {
        memo.assign(n+1,vector<int>(k+1,-1));

        int ans=dp(0,k,n);
        return ans;
    }
};