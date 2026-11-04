class Solution {
public:
    int MOD = 1e9 + 7;
    vector<vector<int>> memo;

    int dp(int curr, int &finish, int fuel, vector<int>& locations){

        if(memo[curr][fuel]!=-1)return memo[curr][fuel];

        long long ans= (curr == finish);

        for(int i=0;i<locations.size();i++){
            if(i==curr)continue;
            
            int d=abs(locations[curr]-locations[i]);
            if(d <= fuel ){
                ans=(ans + dp(i,finish,fuel-d,locations))%MOD;
            }
        }

        return memo[curr][fuel]=ans;
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n=locations.size();
        memo.assign(101,vector<int>(201,-1));
        
        int ans=dp(start,finish,fuel,locations);

        return ans;
    }
};