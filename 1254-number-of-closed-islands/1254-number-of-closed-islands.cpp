class Solution {
private:
    bool isValid(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        return (r>=0 && r<grid.size() && c>=0 && c<grid[0].size() && grid[r][c] == 0 && visited[r][c] == false);
    }
    
    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        if(isValid(r, c, grid, visited) == false){
            return;
        }
        
        visited[r][c] = true;
        dfs(r+1, c, grid, visited);
        dfs(r, c+1, grid, visited);
        dfs(r-1, c, grid, visited);
        dfs(r, c-1, grid, visited);
    }
    
public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for(int r=0; r<rows; r++){
            if(grid[r][0] == 0 && visited[r][0] == false){
                dfs(r, 0, grid, visited);
            }
            if(grid[r][cols-1] == 0 && visited[r][cols-1] == false){
                dfs(r, cols-1, grid, visited);
            }
        }
        
        
        for(int c=0; c<cols ; c++){
            if(grid[0][c] == 0 && visited[0][c] == false){
                dfs(0, c, grid, visited);
            }
            
            if(grid[rows-1][c] == 0 && visited[rows-1][c] == false){
                dfs(rows-1, c, grid, visited);
            }
        }
        
        int closeIsland = 0;
        for(int r=0 ; r<rows ; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c] == 0 && visited[r][c] == false){
                    closeIsland++;
                    dfs(r, c, grid, visited);
                }
            }
        }
        return closeIsland;
    }
};