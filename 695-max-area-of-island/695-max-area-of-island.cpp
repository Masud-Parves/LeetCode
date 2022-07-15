class Solution {
private:
    int fx[4] = {1, -1, 0, 0};
    int fy[4] = {0, 0, 1, -1};
    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        if(r<0 or r==grid.size() or c<0 or c == grid[0].size() or grid[r][c] == 0 or visited[r][c] == true) {
            return 0;
        }
        
        visited[r][c] = true;
        int ret = 1;
        
        for(int i=0; i<4; i++){
            ret += dfs(r+fx[i], c+fy[i], grid, visited);
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
                    int ret = dfs(r, c, grid, visited);
                    result = max(result, ret);
                }
            }
        }
        return result;
    }
};