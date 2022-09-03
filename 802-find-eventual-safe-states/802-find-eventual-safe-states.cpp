class Solution {
private:
    bool dfs(int uNode , vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& pathVisited){
        
        visited[uNode] = pathVisited[uNode] = true;
        
        for(auto& vNode : graph[uNode]){
            if(visited[vNode] == false){
                if(dfs(vNode, graph, visited, pathVisited) == true) {
                    // not contains any cycle's node
                    return true;
                }
            } else if(pathVisited[vNode] == true){
                // contain cycle's node
                return true;
            }
        }
        
        pathVisited[uNode] = false;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int numOfNode = graph.size();
        vector<bool> visited(numOfNode, false);
        vector<bool> pathVisited(numOfNode, false);
        vector<int> safeNodes;
        for(int node = 0; node<numOfNode; node++){
            if(visited[node] == false){
                dfs(node, graph, visited, pathVisited);
            }
        }
        
        for(int i=0; i<numOfNode; i++){
            if(pathVisited[i] == false) safeNodes.push_back(i);
        }
        
        return safeNodes;
    }
};