class Solution {
private:
    int fx[4] = {0, 0, -1, 1};
    int fy[4] = {-1, 1, 0, 0};

    
    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& seen){
        
        if(r<0 or r>=grid.size() or c<0 or c>= grid[0].size() or grid[r][c] == 0){
            return 1;
        }
        
        if(seen[r][c]) return 0;
        
        
        seen[r][c] = true;
        int tot = 0;
        for(int i=0; i<4; i++){
            int r_idx = r + fx[i];
            int c_idx = c + fy[i];
            tot += dfs(r_idx, c_idx, grid, seen);
        }
        return tot;
    }
    
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int perimeter = 0;
        vector<vector<bool>> seen(rows, vector<bool>(cols, false));
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                    if(grid[i][j]) {
                        perimeter = dfs(i, j, grid, seen);
                        return perimeter;
                    }
            }
        }
        return perimeter;
    }
};