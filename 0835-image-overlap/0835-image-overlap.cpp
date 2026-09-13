class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int ans=0;
        vector<pair<int,int>> o1,o2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]==1)o1.push_back({i,j});
                if(img2[i][j]==1)o2.push_back({i,j});
            }
        }
        unordered_map<int,int> mp;
        for(auto& p1:o1){
            for(auto & p2:o2){
                int dx=p2.first-p1.first;
                int dy=p2.second-p1.second;
                mp[ (dx+n)*100 + (dy+n) ]++;
                ans=max(ans,mp[(dx+n)*100 + (dy+n)]);
            }
        }

        return ans;
    }
};