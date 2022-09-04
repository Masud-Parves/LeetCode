class Solution {
private:
    bool dfs(int node, int p, vector<vector<int>>& graph, vector<int>& color){
        
        color[node] = 1 - color[p];
        for(auto& vNode : graph[node]){
            if(color[vNode] == -1){
                if(dfs(vNode, node, graph, color) == false){
                    cout << vNode << endl;
                    return false;
                } 
            } else if(color[vNode] == color[node]){
                return false;
            }
        }
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<vector<int>>graph(n+1);
        for(auto& edge : dislikes){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int> color(n+1, -1);
        color[0] = 0;
        for(int node = 1; node<=n; node++){
            if(color[node] == -1){
                if(dfs(node, 0, graph, color) == false){
                    return false;
                }
            }
        }
        
        return true;
    }
};