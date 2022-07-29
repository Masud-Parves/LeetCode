class Solution {
private:
    int fx[4] = {1, -1, 0, 0};
    int fy[4] = {0, 0, -1, 1};
    void backtrack(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited, int& ret, int& result){
        if(r<0 || r== grid.size() || c<0 || c == grid[0].size() || grid[r][c] == 0 || visited[r][c] == true){
            result = max(ret, result);
            return;
        }
        
        ret += grid[r][c];
        visited[r][c] = true;
        for(int i=0; i<4; i++){
            int r_idx = r+fx[i];
            int c_idx = c+fy[i];
            backtrack(r_idx, c_idx, grid, visited, ret, result);
        }
        ret -= grid[r][c];
        visited[r][c] = false;
        
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int result = 0;
        for(int r = 0; r<rows; r++){
            for(int c = 0; c<cols; c++){
                vector<vector<bool>> visited(rows, vector<bool>(cols, false));
                int ret = 0;
                backtrack(r, c, grid, visited, ret, result);
            }
        }
        return result;
    }
};

/*

[
    [0,6,0],
    [5,8,7],
    [0,9,0]
]

*/