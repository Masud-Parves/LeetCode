class Solution {
private:
    void dfs(int u, int dest, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& result){
        path.push_back(u);
        if(u == dest){
            result.push_back(path);
            return;
        }
        
        for(auto& v : graph[u]){
            dfs(v, dest, graph, path, result);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        int n = graph.size();
        vector<int> path;
        dfs(0, n-1, graph, path, result);
        return result;
    }
};