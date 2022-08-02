class Solution {
private:
    bool dfs(int u, vector<vector<int>>& graph, vector<int>& color, int des){
        if(graph[u].size() == 0){
            return u == des;
        }
        
        color[u] = 1;
        
        for(int v : graph[u]){
            if(color[v] == 1) return false;
            if(color[v] == 0 && dfs(v, graph, color, des) == false){
                return false;
            }
        }
        
        color[u] = 2;
        return true;
    }
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        if(edges.size() == 0) {
            return n == 1;
        }
        // case
        
        vector<vector<int>>graph(n);
        for(auto& edge : edges){
            graph[edge[0]].push_back(edge[1]);
        }
        
        vector<int>color(n, 0);
        
        return dfs(source, graph, color, destination);
    }
};