class Solution {
private:
    void bfs(int src, vector<vector<int>>& mat, vector<bool>& visited){
        queue<int>Q;
        visited[src] = true;
        Q.push(src);
        
        while(!Q.empty()){
            int u = Q.front();
            Q.pop();
            
            for(int i=0; i<mat.size(); i++){
                if(mat[u][i] == 1 && visited[i] == false){
                    Q.push(i);
                    visited[i] = true;
                }
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
                bfs(i, mat, visited);
                ret++;
            }
        }
        return ret;
    }
};