class Solution {
private:
    int fx[4] = {-1, 1, 0, 0};
    int fy[4] = {0, 0, -1, 1};
    
    bool isValid(int r, int c, vector<vector<int>>& grid){
        return (r>=0 && r<grid.size() && c>=0 && c<grid[0].size());
    }
    
    void bfs(int sr, int sc, vector<vector<int>>& grid, vector<vector<int>>& visited, unordered_map<int, int>& compSize, int& color){
        
        queue<pair<int, int>> todo;
        todo.push({sr, sc});
        visited[sr][sc] = color;
        int size = 0;
        while(!todo.empty()){
            auto cell = todo.front();
            todo.pop();
            size++;
            for(int k=0; k<4; k++){
                int r = cell.first + fx[k];
                int c = cell.second + fy[k];
                
                if(isValid(r, c, grid) == false || visited[r][c] > 0 || grid[r][c] == 0) continue;
                
                visited[r][c] = color;
                todo.push({r, c});
            }
            
        }
        //cout << "size = " << size << " " << color << endl;
        compSize[color++] = size;
        return;
        
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int color = 1;
        unordered_map<int, int> componentSize;
        
        vector<vector<int>> visited(rows, vector<int>(cols, -1));
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols ; c++){
                if(grid[r][c] == 1 && visited[r][c] == -1){
                    bfs(r, c, grid, visited, componentSize, color);
                }
            }
        }
        
        // if all are connected, or there is no 0 in grid
        int maxIsland = 0;
        
        for(auto& com : componentSize){
            maxIsland = max(maxIsland, com.second);
            //cout << com.first << " " << com.second << endl;
        }
        
        // apply one operation
        
        
        
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols ; c++){
                
                if(grid[r][c] == 0 && visited[r][c] == -1){
                    int currIsland = 1;
                    unordered_map<int, int> taken;
                    for(int k=0; k<4; k++){
                        int nr = r + fx[k];
                        int nc = c + fy[k];
                        
                        if(isValid(nr, nc, grid) == true){
                            int color = visited[nr][nc];
                            if(taken.find(color) == taken.end()){
                                currIsland += componentSize[color];
                                taken[color]++;
                            }
                        }
                    }
                    maxIsland = max(maxIsland, currIsland);
                }
            }
        }
        
        return maxIsland; 
    }
};