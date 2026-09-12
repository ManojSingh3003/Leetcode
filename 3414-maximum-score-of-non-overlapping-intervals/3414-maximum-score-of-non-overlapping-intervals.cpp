class Solution {
private:
    pair<long long,vector<int>> dp(int i,int x,vector<vector<int>> &interval,vector<int>& next_ind,vector<vector< pair<long long,vector<int>> >>& memo){
        if(i==interval.size() || x==4){
            return {0,{}};
        }
        if(memo[i][x].first!=-1)return memo[i][x];

        pair< long long,vector<int> > ans1=dp(i+1,x,interval,next_ind,memo);
        
        int ni=next_ind[i];

        pair<long long,vector<int>> ans2=dp(ni,x+1,interval,next_ind,memo);
        ans2.first+=interval[i][2];
        ans2.second.push_back(interval[i][3]);

        sort(ans2.second.begin(),ans2.second.end());

        if(ans2.first>ans1.first){
            return memo[i][x]=ans2;
        }else if(ans2.first<ans1.first){
            return memo[i][x]=ans1;
        }else{
            if(ans1.second>ans2.second){
                return memo[i][x]=ans2;
            }else{
                return memo[i][x]=ans1;
            }
        }

    }
public:
    vector<int> maximumWeight(vector<vector<int>>& lrw) {
        int n=lrw.size();
        vector<vector<int>> interval(lrw.size(),vector<int>(4,0));
        for(int i=0;i<lrw.size();i++){
            interval[i]={lrw[i][0],lrw[i][1],lrw[i][2],i};
        }
        sort(interval.begin(),interval.end());

        vector<int>next_ind(n,n);
        for(int i=0;i<n;i++){
            int st=i+1,ed=interval.size()-1;
            while(st<=ed){
                int mid=st+(ed-st)/2;
                if(interval[mid][0]>interval[i][1]){
                    next_ind[i]=mid;
                    ed=mid-1;
                }else{
                    st=mid+1;
                }
            }
        }

        vector<vector< pair<long long,vector<int>> >> memo(interval.size(),vector<pair<long long,vector<int>>>(5,{-1,{}}));

        return dp(0,0,interval,next_ind,memo).second;
    }
};