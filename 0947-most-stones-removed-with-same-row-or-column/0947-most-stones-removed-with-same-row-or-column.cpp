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
    int removeStones(vector<vector<int>>& s) {
        int n=s.size();
        DSU d(20007);
        for(int i=0;i<n;i++){
            d.unite(s[i][0],s[i][1]+10001);
        }
        unordered_set<int> c;
        for(int i = 0; i < n; i++){
            c.insert(d.find(s[i][0]));
        }
        return n-c.size();
    }
};