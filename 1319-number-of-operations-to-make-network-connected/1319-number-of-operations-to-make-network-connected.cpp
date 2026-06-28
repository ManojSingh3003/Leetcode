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
    int makeConnected(int n, vector<vector<int>>& c) {
        int edges=c.size();
        if(edges+1 < n)return -1;
        
        DSU d(n);

        for(int i=0;i<edges;i++){
            d.unite(c[i][0],c[i][1]);
        }
        int ans=0;
        for(int i=1;i<n;i++){
            if(d.find(0)!=d.find(i)){
                ans++;
                d.unite(0,i);
            }
        }
        return ans;
    }
};