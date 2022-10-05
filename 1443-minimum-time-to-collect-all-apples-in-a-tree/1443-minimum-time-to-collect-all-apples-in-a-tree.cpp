class Solution {
private:
    void dfs(int uNode, int p, vector<vector<int>>& graph, vector<int>& childs, vector<bool>& hasApple){
        //cout << uNode << endl;
        childs[uNode] = hasApple[uNode];
        for(auto& vNode : graph[uNode]){
            if(vNode == p) continue;
            dfs(vNode, uNode, graph, childs, hasApple);
            childs[uNode] += childs[vNode];
        }
        return;
    }
    
    void dfs2(int uNode, int p, vector<vector<int>>& graph, vector<int>& childs, int& path){
        path++;
        for(auto& vNode : graph[uNode]){
            if(vNode == p or childs[vNode]==0) continue;
            dfs2(vNode, uNode, graph, childs, path);
        }
        path++;
    }

public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n);
        for(auto& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int> childs(n);
        dfs(0, -1, graph, childs, hasApple);
        for(int i=0; i<n; i++){
            cout << childs[i] << " ";
        }
        if(childs[0] == 0) return 0;
        int path = 0;
        dfs2(0, -1, graph, childs, path);
        
        return path-2;
    }
};