//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    bool dijkstra(int src, vector<vector<pair<int, int>>>& graph, vector<int>& root, int n){
        vector<int> dis(n+1, 1e9);
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>todo;
        dis[src] = 0;
        todo.push({0, src});
        
        while(!todo.empty()){
            auto nodeInfo = todo.top();
            todo.pop();
            int distance = nodeInfo.first;
            int uNode = nodeInfo.second;
            
            for(auto& child : graph[uNode]){
                int vNode = child.second;
                int vCost = child.first;
                if(dis[vNode]>distance + vCost){
                    dis[vNode] = distance + vCost;
                    root[vNode] = uNode;
                    todo.push({dis[vNode], vNode});
                }
            }
        }
        
        return dis[n] != 1e9;
    }

public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(n+1);
        for(auto& edge : edges){
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].push_back({w, v});
            graph[v].push_back({w, u});
        }
        
        vector<int> root(n+1);
        for(int i=1; i<=n; i++){
            root[i] = i;
        }
        bool isPossible = dijkstra(1, graph, root, n);
        if(isPossible == false) return {-1};
        
        vector<int> path;
        int node = n;
        while(root[node] != node){
            path.push_back(node);
            node = root[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        return path;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends