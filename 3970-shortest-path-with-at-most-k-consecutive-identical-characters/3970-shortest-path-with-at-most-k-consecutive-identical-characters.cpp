class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> g(n);
        for(int i=0;i<edges.size();i++){
            g[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }

        vector<vector<int>>dist(n,vector<int>(k+1,1e9));

        priority_queue< pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>>>,greater<> > pq;

        pq.push({0,{0,1}});
        dist[0][1]=0;

        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();

            if(node == n-1){
                return d;
            }
            if(d>dist[node][c])continue;

            for( auto &it:g[node]){
                int nc=c;
                if(labels[node]==labels[it.first]){
                    nc++;
                }else nc=1;

                if((nc<=k) && (d+it.second <dist[it.first][nc])){
                    dist[it.first][nc]=d+it.second;
                    pq.push({dist[it.first][nc],{it.first,nc}});
                }
            }
            
        }
        return -1;
    }
};