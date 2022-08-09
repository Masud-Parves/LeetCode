class Solution {
private:
    int fx[4] = {0, 0, 1, -1};
    int fy[4] = {1, -1, 0, 0};
    void dfs(int r, int c, vector<vector<bool>>& visited, vector<vector<char>>& grid){
        int row = grid.size(), col = row ? grid[0].size() : 0;
        if(r<0 or r==row or c<0 or c==col or
           visited[r][c] == true or grid[r][c] == '0') {
            return;
        }
        
        visited[r][c] = true;
        for(int k=0; k<4; k++){
            dfs(r+fx[k], c+fy[k], visited, grid);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(), col = row ? grid[0].size() : 0;
        int islands = 0;
        
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == '1' && visited[i][j] == false){
                    dfs(i, j, visited, grid);
                    islands++;
                }
            }
        }
        return islands;
    }
};