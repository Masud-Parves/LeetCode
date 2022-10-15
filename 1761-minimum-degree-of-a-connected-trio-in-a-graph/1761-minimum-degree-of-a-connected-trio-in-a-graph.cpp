class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n+1, vector<int>(n+1, 0));
        vector<int> degree(n+1, 0);
        for(auto& edge : edges){
            adj[edge[0]][edge[1]] = 1;
            adj[edge[1]][edge[0]] = 1;
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        
        int minVal = INT_MAX;
        for(int u=1; u<=n ; u++){
            for(int v = u+1; v<=n ; v++){
                if(adj[u][v] == 1){
                    for(int w = v+1; w<=n; w++){
                        if(adj[v][w] == 1 && adj[w][u] == 1){
                            minVal = min(minVal, degree[u]+degree[v]+degree[w] - 6);
                        }
                    }
                }
                
            }
        }
       
        return minVal == INT_MAX ? -1 : minVal;
    }
};