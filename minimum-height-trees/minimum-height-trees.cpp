class Solution {
private:
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<int> result;
        vector<unordered_set<int>> graph(n);
        
        for(auto& edge : edges){
            int u = edge[0], v = edge[1];
            graph[u].insert(v);
            graph[v].insert(u);
        }
        
        queue<int>Q;
        
        for(int nd=0; nd<n; nd++){
            if(graph[nd].size() == 1){
                Q.push(nd);
            }
        }
        
        while(n>2){
            int del_node = Q.size();
            n -= del_node;
            for(int i=0; i<del_node; i++){
                int u = Q.front();
                Q.pop();
                for(auto& v : graph[u]){
                    graph[v].erase(u);
                    if(graph[v].size() == 1) Q.push(v);
                }
            }
        }
        
        while(!Q.empty()){
            result.push_back(Q.front());
            Q.pop();
        }
        
        return result;
    }
};