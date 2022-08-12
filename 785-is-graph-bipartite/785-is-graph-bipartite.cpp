// -1 unvisited/ uncolored
// white 1
// black 0


class Solution {
public:
    
    bool dfs(int u, int clr, vector<int>& color, vector<vector<int>>& graph){
        
        color[u] = clr;
        for(auto& v : graph[u]){
            if(color[v] != -1){
                if(color[v] == clr) return false;
            } else {
                if(dfs(v, 1-clr, color, graph) == false) return false;
            }
        }
        return true;
    }
    
     bool dfs(vector<vector<int>> &graph, int cur, int clr, vector<int> &color){
        color[cur] = clr;
        for(auto &child : graph[cur]){
            if(color[child] != -1){
                if(clr == color[child]) return false;
            }else{
                if(dfs(graph, child, abs(clr-1), color) == false) return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int node = graph.size();
        
        vector<int>color(node, -1);
        bool result = true;
        for(int i=0; i<node ; i++){
            if(color[i] == -1){
                result &= dfs(i, 0, color, graph);
            }
        }
        return result;
    }
};