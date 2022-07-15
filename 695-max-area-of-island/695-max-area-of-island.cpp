class Solution {
private:
    int fx[4] = {1, -1, 0, 0};
    int fy[4] = {0, 0, 1, -1};
    int bfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        queue<pair<int, int>> Q;
        Q.push({r, c});
        visited[r][c] = true;
        int ret = 0;
        while(!Q.empty()){
            pair<int, int> node = Q.front();
            Q.pop();
            ret++;
            int ur = node.first;
            int uc = node.second;
            
            for(int i=0; i<4; i++){
                int vr = ur + fx[i];
                int vc = uc + fy[i];
                
                if(vr>=0 && vr<grid.size() && vc>=0 && vc<grid[0].size() && visited[vr][vc] == false && grid[vr][vc] == 1){
                    visited[vr][vc] = true;
                    Q.push({vr, vc});
                }
            }
        }
        return ret;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int result = 0;
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(visited[r][c] == false && grid[r][c] == 1){
                    int ret = bfs(r, c, grid, visited);
                    result = max(result, ret);
                }
            }
        }
        return result;
    }
};