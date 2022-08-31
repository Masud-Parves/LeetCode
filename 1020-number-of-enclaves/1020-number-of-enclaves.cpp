class Solution {
private:
    int fx[4] = {1, -1, 0, 0};
    int fy[4] = {0, 0, -1, 1};
    bool isBoundaryCell(int r, int c, int rows, int cols){
        return (r==0 || c == 0 || r==rows-1 || c == cols-1);
    }
    
    bool isValid(int r, int c, int rows, int cols, vector<vector<bool>>& visited){
        return (r>=0 && r<rows && c>=0 && c<cols && visited[r][c] == false);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int lends = 0;
        queue<pair<int, int>>Q;
        for(int r=0; r<rows ; r++){
            for(int c=0; c<cols; c++){
                if(isBoundaryCell(r, c, rows, cols) && grid[r][c] == 1) {
                    Q.push({r, c});
                    visited[r][c] = true;
                } else if(grid[r][c] == 1){
                    lends++;
                }
            }
        }
    
        while(!Q.empty()){
            int ur = Q.front().first;
            int uc = Q.front().second;
            Q.pop();
            
            for(int i=0; i<4; i++){
                int vr = ur + fx[i];
                int vc = uc + fy[i];
                if(isValid(vr, vc, rows, cols, visited) && grid[vr][vc] == 1){
                    visited[vr][vc] = true;
                    Q.push({vr, vc});
                    lends--;
                }
            }
        }
        return lends;
    }
};