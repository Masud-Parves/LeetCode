class Solution {
private:
    void dfs(int u, vector<vector<int>>& mat, vector<bool>& visited){
        if(visited[u] == true ) return;
        
        visited[u] = true;
        for(int i=0; i<mat.size(); i++){
            if(mat[u][i] == 1){
                dfs(i, mat, visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<bool> visited(n, false);
        int ret = 0;
        for(int i=0; i<n; i++){
            if(visited[i] == false){
                dfs(i, mat, visited);
                ret++;
            }
        }
        return ret;
    }
};