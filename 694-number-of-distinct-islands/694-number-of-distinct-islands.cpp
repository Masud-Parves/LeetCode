class Solution {
private:
    int fx[4] = {1, -1, 0, 0};
    int fy[4] = {0, 0, -1, 1};
    
    bool isValid(int r, int c, vector<vector<int>>& grid){
        return (r>=0 && r<grid.size() && c>=0 && c<grid[0].size() && grid[r][c] == 1);
    }
    void bfs(int sr, int sc, vector<vector<int>>& grid, vector<vector<bool>>& visited, set<vector<pair<int, int>>>& unique){
        queue<pair<int, int>> Q;
        vector<pair<int, int>> shape;
        visited[sr][sc] = true;
        Q.push({sr, sc});
        shape.push_back({sr-sr, sc-sc});
        while(!Q.empty()){
            int ur = Q.front().first;
            int uc = Q.front().second;
            Q.pop();
            
            for(int i=0; i<4; i++){
                int vr = ur + fx[i];
                int vc = uc + fy[i];
                if(isValid(vr, vc, grid) && visited[vr][vc] == false){
                    visited[vr][vc] = true;
                    Q.push({vr, vc});
                    shape.push_back({vr-sr, vc-sc});
                }
            }
        }
        unique.insert(shape);
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
                    bfs(r, c, grid, visited, unique);
                }
            }
        }
        return unique.size();
    }
};