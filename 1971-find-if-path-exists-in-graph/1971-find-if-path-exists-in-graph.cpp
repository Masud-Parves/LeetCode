class Solution {
private:
    void bfs(int source, vector<int> adj[], vector<bool>& visited){
        queue<int>todo;
        todo.push(source);
        visited[source] = true;
        
        while(!todo.empty()){
            int uNode = todo.front();
            todo.pop();
            
            for(auto& vNode : adj[uNode]){
                if(visited[vNode] == false){
                    todo.push(vNode);
                    visited[vNode] = true;
                }
            }
        }
        return;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        
        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        
        vector<bool>visited(n, false);
        bfs(source, adj, visited);
        
        return visited[destination];
    }
};