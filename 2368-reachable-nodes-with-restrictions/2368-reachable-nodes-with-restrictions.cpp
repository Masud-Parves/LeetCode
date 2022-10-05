class Solution {
private:
    void dfs(int uNode, unordered_map<int, bool>& seen, vector<vector<int>>& graph, int& visited){
        visited++;
        seen[uNode] = true;
        
        for(auto& vNode : graph[uNode]){
            if(seen.find(vNode) == seen.end()){
                dfs(vNode, seen, graph, visited);
            }
        }
        return;
    }
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> graph(n);
        for(auto& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        unordered_map<int, bool> seen;
        for(int node : restricted){
            seen[node] = true;
        }
        int visitedNode = 0;
        dfs(0, seen, graph, visitedNode);
        return visitedNode;
    }
};