class Union_Find{
private:
    vector<int>root;
    int count;
public:
    Union_Find(vector<vector<char>>& grid){
        int row = grid.size(), col = row ? grid[0].size() : 0;
        count = 0;
        for(int i=0; i<row ; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == '1'){
                    root.push_back(i*col + j);
                    count++;
                } else {
                    root.push_back(-1);
                }
            }
        }
    }
    
    int Find(int x){
        if(x == root[x]){
            return x;
        }
        return root[x] = Find(root[x]);
    }
    
    void Union(int x, int y){
        int rootX = Find(x);
        int rootY = Find(y);
        if(rootX == rootY) return;
        root[rootY] = rootX;
        count--;
    }
    
    int getCount(){
        return count;
    }
    
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(), col = row ? grid[0].size() : 0;
        int fx[4] = {0, 0, -1, 1};
        int fy[4] = {1, -1, 0, 0};
        
        Union_Find dsu(grid);
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for(int r=0; r<row; r++){
            for(int c=0; c<col; c++){
                if(grid[r][c] == '1' && visited[r][c]==false){
                    visited[r][c] = true;
                    for(int k=0; k<4; k++){
                        int nr = r + fx[k];
                        int nc = c + fy[k];
                        if(nr>=0 && nr<row && nc>=0 && nc<col && grid[nr][nc] == '1' && visited[nr][nc] == false){
                            dsu.Union(r*col + c, nr*col+nc);
                        }
                    }
                }
            }
        }
        
        return dsu.getCount();
    }
};