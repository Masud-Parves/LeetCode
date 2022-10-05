class Solution {
private:
    int dfs(int uNode, int p, vector<vector<int>>& graph, vector<int>& childs, vector<bool>& hasApple){
        int childsCost = 0;
        for(auto& vNode : graph[uNode]){
            if(vNode == p) continue;
            childsCost += dfs(vNode, uNode, graph, childs, hasApple);
        }
        if(childsCost>0 || hasApple[uNode] == true){
            return childsCost + 2;   
        }
        return 0;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n);
        for(auto& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int> childs(n);
        int cost = dfs(0, -1, graph, childs, hasApple);
        return cost == 0 ? cost : cost-2;
    }
};