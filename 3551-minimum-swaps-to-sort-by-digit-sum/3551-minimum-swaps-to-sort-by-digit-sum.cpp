class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> x;
        for(int i=0;i<n;i++){
            int s=0;
            int y=nums[i];
            while(y){
                s+=y%10;
                y/=10;
            }
            x.push_back({s,nums[i]});
        }
        sort(x.begin(),x.end());
        vector<int> x1;
        for(int i=0;i<n;i++){
            x1.push_back(x[i].second);
        }
        
        map<int,int> ind;
        for(int i=0;i<n;i++){
            ind[x1[i]]=i;
        }
        vector<int> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i] || ind[nums[i]]==i)continue;

            int c=0;
            int j=i;
            while(!vis[j]){
                vis[j]=1;
                j=ind[nums[j]];
                c++;
            }
            if(c>1){
                ans+=c-1;
            }
        }
        return ans;
    }
};