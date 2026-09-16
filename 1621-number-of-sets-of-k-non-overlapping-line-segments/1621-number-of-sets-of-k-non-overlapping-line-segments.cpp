class Solution {
const int mod=1e9+7;
vector<vector<vector<int>>> memo;
private:
    int dp(int i,int k,int on,int n){
        if(i==n){
            if(k==0)return 1;
            else return 0;
        }
        if(k==0)return 1;

        if(memo[i][k][on]!=-1)return memo[i][k][on];

        int ans=0;
        if(on){
            ans = (ans + dp(i+1, k, 1, n)) % mod;
            ans = (ans + dp(i, k-1, 0, n)) % mod;
        }else{
            ans = (ans + dp(i+1, k, 0, n)) % mod;
            ans = (ans + dp(i+1,k,1,n)) % mod;
        }
        return memo[i][k][on]=ans;
    }
public:
    int numberOfSets(int n, int k) {
        memo.assign(n+1,vector<vector<int>>(k+1,vector<int>(2,-1)));

        int ans=dp(0,k,0,n);
        return ans;
    }
};