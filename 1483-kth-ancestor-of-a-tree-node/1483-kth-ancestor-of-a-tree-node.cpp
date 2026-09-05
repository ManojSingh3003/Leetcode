class TreeAncestor {
    int log;
    vector<vector<int>> up;
public:
    TreeAncestor(int n, vector<int>& parent) {
        log=0;
        while((1<<log) <= n)log++;
        up=vector<vector<int>>(n,vector<int>(log,-1));

        parent[0]=-1;
        for(int v=0;v<n;v++){
            up[v][0]=parent[v];
        }
        for(int i=1;i<log;i++){
            for(int v=0;v<n;v++){
                if(up[v][i-1]!=-1) up[v][i]= up[ up[v][i-1] ][i-1];
            }
        }
        
    }
    
    int getKthAncestor(int node, int k) {
        if(k >= (1<<log) )return -1;
        for(int i=0;i<log;i++){
            if( (k>>i) & 1 ){
                node=up[node][i];
                if(node==-1)return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */