class Solution {
    struct DSU {
        vector<int> p, sz;
        
        DSU(int n) {
            p.resize(n);
            sz.resize(n, 1);
            for(int i = 0; i < n; i++) p[i] = i;
        }
        
        int find(int i) {
            return p[i] == i ? i : p[i] = find(p[i]);
        }
        
        void unite(int i, int j) {
            int u = find(i), v = find(j);
            if(u != v) {
                if(sz[u] < sz[v]) swap(u, v);
                p[v] = u;
                sz[u] += sz[v];
            }
        }
    };
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& a) {
        int n=a.size();
        DSU d(n);

        unordered_map<string ,int> etn;

        for(int i=0;i<n;i++){
            for(int j=1;j<a[i].size();j++){
                string e=a[i][j];
                if(etn.find(e) !=etn.end()){
                    d.unite(i,etn[e]);
                }else{
                    etn[e]=i;
                }
            }
        }

        unordered_map<int,vector<string>> ma;
        for(auto &it:etn){
            string e=it.first;
            int node=it.second;

            int root=d.find(node);
            ma[root].push_back(e);
        }

        vector<vector<string>> ans;
        for (auto& pair : ma) {
            int rootNode = pair.first;
            vector<string> emails = pair.second;
            
            sort(emails.begin(), emails.end());
            
            vector<string> account;
            account.push_back(a[rootNode][0]);
            account.insert(account.end(), emails.begin(), emails.end());
            
            ans.push_back(account);
        }
        return ans;
    }
};