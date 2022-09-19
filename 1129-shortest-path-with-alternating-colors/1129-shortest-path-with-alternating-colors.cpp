class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> result(n);
        if(n==0){
            return result;
        }
        vector<pair<int, int>> adj[n];
        for(auto& redEdge : redEdges){
            adj[redEdge[0]].push_back({redEdge[1], 0});
        }
        
        for(auto& blueEdge : blueEdges){
            adj[blueEdge[0]].push_back({blueEdge[1], 1});
        }
        
        
        vector<vector<int>> dis(n, vector<int>(2, INT_MAX));
        
        queue<pair<int, int>> Q;
        Q.push({0, 0});
        Q.push({0, 1});
        
        dis[0][0] = 0;
        dis[0][1] = 0;
        
        while(!Q.empty()){
            auto node = Q.front();
            int uNode = node.first;
            int uColor = node.second;
            Q.pop();
            
            for(auto& childNode : adj[uNode]){
                int vNode = childNode.first;
                int vColor = childNode.second;
                
                if(vColor == 1-uColor && dis[vNode][vColor]>dis[uNode][uColor]+1){
                    dis[vNode][vColor] = dis[uNode][uColor]+1;
                    Q.push({vNode, vColor});
                }
            }
        }
        
        for(int node = 0; node<n; node++){
            int distance = min(dis[node][0], dis[node][1]);
            result[node] =  distance == INT_MAX ? -1 : distance;
        }
        return result;
    }
};