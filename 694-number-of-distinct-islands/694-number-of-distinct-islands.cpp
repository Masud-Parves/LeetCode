class Solution {
private:
    int fx[4] = {1, -1, 0, 0};
    int fy[4] = {0, 0, -1, 1};
    
    bool isValid(int r, int c, vector<vector<int>>& grid){
        return (r>=0 && r<grid.size() && c>=0 && c<grid[0].size() && grid[r][c] == 1);
    }
    
    
    void dfs(int r, int c, vector<vector<int>>& grid, int baseRow, int baseCol, vector<vector<bool>>& visited, vector<pair<int, int>>& shape){
        if(r<0 || r==grid.size() || c<0 || c == grid[0].size() || grid[r][c] == 0 || visited[r][c] == true){
            return;
        }
        
        visited[r][c] = true;
        shape.push_back({r-baseRow, c-baseCol});
        for(int i=0; i<4; i++){
            int vr = r + fx[i];
            int vc = c + fy[i];
            dfs(vr, vc, grid, baseRow, baseCol, visited, shape);
        }
        return;
    }
    
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        set<vector<pair<int, int>>> unique;
        
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c] == 1 && visited[r][c] == false){
                    vector<pair<int, int>> shape;
                    dfs(r, c, grid, r, c, visited, shape);
                    unique.insert(shape);
                }
            }
        }
        return unique.size();
    }
};