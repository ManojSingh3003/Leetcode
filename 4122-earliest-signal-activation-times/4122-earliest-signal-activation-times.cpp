class Solution {
public:
    vector<long long> earliestActivationTimes(int n, vector<vector<int>>& edges, vector<int>& requiredSignals) {
        vector<vector<pair<int, int>>>adj(n);

        for(auto e:edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>q;
        vector<bool>vis(n);

        vector<long long>t(n, -1);
        t[0] = 0;

        for(auto [u, delay]:adj[0]) {
            q.push({delay, u});
        }

        while(!q.empty()) {
            auto [cost, s] = q.top();
            q.pop();

            requiredSignals[s]--;
            if(s == 0 or requiredSignals[s] != 0) {
                continue;
            }
            
            t[s] = cost;

            for(auto [u, delay]:adj[s]) {
                q.push({t[s]+delay, u});
            }
        }

        return t;
    }
};