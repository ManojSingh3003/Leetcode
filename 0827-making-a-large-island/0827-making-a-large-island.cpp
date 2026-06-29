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
    int largestIsland(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        DSU d(n*m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==1){
                    if(i-1>=0){
                        if(g[i-1][j]==1){
                            d.unite(i*m+j,(i-1)*m+j);
                        }
                    }
                    if(i+1<n){
                        if(g[i+1][j]==1){
                            d.unite(i*m+j,(i+1)*m+j);
                        }
                    }
                    if(j-1>=0){
                        if(g[i][j-1]==1){
                            d.unite(i*m+j,i*m+(j-1));
                        }
                    }
                    if(j+1<m){
                        if(g[i][j+1]==1){
                            d.unite(i*m+j,i*m+(j+1));
                        }
                    }
                }
            }
        }
        int ans=0;
        int z=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==0){
                    z++;
                    int x=1;
                    set<int> s;
                    if(i-1>=0){
                        if(g[i-1][j]==1){
                            s.insert(d.find((i-1)*m+j));
                        }
                    }
                    if(i+1<n){
                        if(g[i+1][j]==1){
                            s.insert(d.find((i+1)*m+j));
                        }
                    }
                    if(j-1>=0){
                        if(g[i][j-1]==1){
                            s.insert(d.find(i*m+(j-1)));
                        }
                    }
                    if(j+1<m){
                        if(g[i][j+1]==1){
                            s.insert(d.find(i*m+(j+1)));
                        }
                    }
                    for(auto &it:s){
                        x+=d.sz[it];
                    }
                    ans=max(ans,x);
                }
            }
        }
        if(z==0){
            return n*m;
        }
        return ans;
    }
};