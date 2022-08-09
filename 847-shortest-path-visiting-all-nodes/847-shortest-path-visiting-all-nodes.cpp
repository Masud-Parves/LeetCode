class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        
        int n = graph.size();
        if(n == 1) return 0;
        int endMask = (1<<n) - 1;
        queue<pair<int, pair<int, int>>>Q;
        set<pair<int, int>>visited;
        
        for(int i=0; i<n; i++){
            Q.push({i, {0, 1<<i}});
            visited.insert({i, 1<<i});
        }
        
        while(!Q.empty()){
            auto node = Q.front();
            Q.pop();
            int u = node.first;
            int d = node.second.first;
            int mask = node.second.second;
            
            for(int v : graph[u]){
                int newMask = mask | (1<<v);
                
                if(newMask == endMask){
                    return d+1;
                }
                
                if(visited.count({v, newMask})==0){
                    Q.push({v, {d+1, newMask}});
                    visited.insert({v, newMask});
                    
                }
            }
            
        }
        return -1;
    }
};