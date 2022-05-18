class Solution {
public:
    vector<vector<int>>graph;
    vector<vector<int>> bridges;
    vector<int>low, tin;
    vector<bool>visited;
    int timer = 0;
    void dfs(int u, int p){
        
        visited[u] = true;
        tin[u] = low[u] = ++timer;
        for(auto& to : graph[u]){
            if(to == p) continue;
            
            if(visited[to]){
                low[u] = min(low[u], tin[to]);
            } else {
                dfs(to, u);
                low[u] = min(low[to], low[u]);
                if (low[to] > tin[u])
                bridges.push_back({u, to});
            }
        }
        
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> edges;

        graph.resize(n);
        for(auto& edge : connections){
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        visited.resize(n, false);
        low.resize(n), tin.resize(n);
        
        dfs(0, -1);
        return bridges;
    }
};