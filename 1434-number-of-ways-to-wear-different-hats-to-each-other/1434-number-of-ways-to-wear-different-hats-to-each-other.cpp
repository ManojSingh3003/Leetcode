class Solution {
    int mod=1e9+7;

    int solve(int ind,int mask,int tar,vector<vector<int>>& p,vector<vector<int>>& memo){
        if(mask == tar)return 1;
        if(ind>40)return 0;

        if(memo[ind][mask]!=-1)return memo[ind][mask];

        long long way=solve(ind+1,mask,tar,p,memo);
        for(int i=0;i<p[ind].size();i++){
            if((mask & (1<<p[ind][i])) ==0){
                int new_mask=(mask | (1<<p[ind][i]));
                way=(way+solve(ind+1,new_mask,tar,p,memo))%mod;
            }
        }
        return memo[ind][mask]=way;
    }
    
public:
    int numberWays(vector<vector<int>>& hats) {
        int n=hats.size();

        vector<vector<int>> p(41);
        for(int i=0;i<n;i++){
            for(int j=0;j<hats[i].size();j++){
                p[hats[i][j]].push_back(i);
            }
        }
        
        vector<vector<int>> memo(41,vector<int>(1<<n,-1));

        int ways=solve(1,0,(1<<n)-1,p,memo);
        return ways;
    }
};