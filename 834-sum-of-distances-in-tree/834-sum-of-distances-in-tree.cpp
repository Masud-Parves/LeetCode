class Solution {
    private:
    void dfs(int node, int p, vector<vector<int>>& graph, vector<int>& childs, vector<int>& level){
        
        for(int vNode : graph[node]){
            if(vNode == p) continue;
            level[vNode] = level[node]+1;
            dfs(vNode, node, graph, childs, level);
            childs[node] = childs[vNode] + childs[node]; 
        }
    }
    
    void dfs2(int uNode, int p, int n, vector<vector<int>>& graph, vector<int>& answer, vector<int>& childs){
        for(int vNode: graph[uNode]){
            if(vNode == p) continue;
            answer[vNode] = answer[uNode] - childs[vNode] + (n-childs[vNode]);
            dfs2(vNode, uNode, n, graph, answer, childs);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> answer(n, 0);
        vector<vector<int>> graph(n);
        for(auto& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int> subtreeChilds(n, 1);
        vector<int> level(n, 0);
        
        dfs(0, -1, graph, subtreeChilds, level);
        for(int i=0; i<n; i++){
            answer[0] += level[i];
        }
        //answer[i] = answer[par] - childs[curr] + (totalNode-childs[curr]);
        dfs2(0, -1, n, graph, answer, subtreeChilds);
        
        return answer;
    }
};