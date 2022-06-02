// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  private:
    bool bfs(int src, vector<int> adj[], vector<bool>& visited, int n){
        
        vector<int>parent(n, -1);
        queue<int>Q;
        Q.push(src);
        visited[src] = true;
        
        
        
        while(!Q.empty()){
            int uNode = Q.front();
            Q.pop();
            
            for(int vNode : adj[uNode]){
                if(visited[vNode] == false){
                    visited[vNode] = true;
                    Q.push(vNode);
                    parent[vNode] = uNode;
                } else if(parent[uNode]!=vNode){
                    return true;
                }
            }
        }
        
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        vector<bool>visited(V, false);
        
        for(int i=0; i< V; i++){
            if(visited[i] == false){
                bool ret = bfs(i, adj, visited, V);
                if(ret == true) return true;
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends