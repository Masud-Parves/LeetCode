class Solution {
private:
    int fx[4] = {1, -1, 0, 0};
    int fy[4] = {0, 0, -1, 1};
    
    bool isValid(int r, int c, vector<vector<int>>& grid, int color){
        return r<0 || c<0 || r == grid.size() || c == grid[0].size() || abs(grid[r][c]) != color;
    }
    void dfs(int r, int c, vector<vector<int>>& grid, int color){
        grid[r][c] = -color;
        
        int count = 0;
        for(int i=0; i<4; i++){
            int rIdx = r + fx[i];
            int cIdx = c + fy[i];
            if(isValid(rIdx, cIdx, grid, color) == true) continue;
            count++;
            if(grid[rIdx][cIdx]>0){
                dfs(rIdx, cIdx, grid, color);
            }
        }
        if(count==4) grid[r][c] = color;
    }
    
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int newColor) {
        int rows = grid.size(), cols = grid[0].size();
        
        dfs(row, col, grid, grid[row][col]);
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols ; c++){
                if(grid[r][c]<0) grid[r][c] = newColor;
            }
        }
        return grid;
    }
};