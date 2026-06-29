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
    int swimInWater(vector<vector<int>>& g) {
        int n=g.size();
        for(int t=0;t<=n*n;t++){
            DSU d(n*n);
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(g[i][j]<=t){
                    if(i-1>=0){
                        if(g[i-1][j]<=t){
                            d.unite(i*n+j,(i-1)*n+j);
                        }
                    }
                    if(i+1<n){
                        if(g[i+1][j]<=t){
                            d.unite(i*n+j,(i+1)*n+j);
                        }
                    }
                    if(j-1>=0){
                        if(g[i][j-1]<=t){
                            d.unite(i*n+j,i*n+(j-1));
                        }
                    }
                    if(j+1<n){
                        if(g[i][j+1]<=t){
                            d.unite(i*n+j,i*n+(j+1));
                        }
                    }
                    }
                    
                }
            }
            if(d.find(0)==d.find((n-1)*(n+1)))return t;
        }
        return -1;
    }
};