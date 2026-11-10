class Solution {
public:
    void dfs(int node,vector<vector<int>>& g, vector<int>& nums,vector<bool>& visited, unordered_set<int>& seen){
        if(visited[node])return;

        visited[node]=1;
        seen.insert(nums[node]);

        for(auto &it:g[node]){
            dfs(it,g,nums,visited,seen);
        }
    }

    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n=parents.size();

        vector<vector<int>> g(n);
        for(int i=1;i<n;i++){
            g[parents[i]].push_back(i);
        }

        vector<int> ans(n,1);

        int x=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                x=i;
                break;
            }
        }
        if(x==-1)return ans;

        unordered_set<int> seen;
        vector<bool> visited(n,false);

        int mex=1;
        int cur=x;

        while(cur!=-1){
            dfs(cur,g,nums,visited,seen);

            while(seen.count(mex))mex++;

            ans[cur]=mex;
            cur=parents[cur];
        }

        return ans;
    }
};