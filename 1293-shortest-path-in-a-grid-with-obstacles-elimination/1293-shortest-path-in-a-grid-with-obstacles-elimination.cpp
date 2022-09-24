class Solution {
private:
    int fx[4] = {-1, 1, 0, 0};
    int fy[4] = {0, 0, 1, -1};
    
    bool isValid(int r, int c, vector<vector<int>>& grid){
        return (r>=0 && r<grid.size() && c>=0 && c<grid[0].size());
    }
    
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int rows = grid.size(), cols = grid[0].size();
        if(rows == 1 && cols == 1) return 0;
        
        vector<vector<unordered_set<int>>> visited(rows, vector<unordered_set<int>>(cols, unordered_set<int>{}));
        queue<pair<pair<int, int>, int>> todo;
        
        todo.push({{0, 0}, k});
        visited[0][0].insert(k);
        int steps = 0;
        while(!todo.empty()){
            int size = todo.size();
                    
            steps++;
            
            for(int i=0; i<size; i++){
                auto cell = todo.front();
                todo.pop();
                for(int k =0; k<4; k++){
                    int r = cell.first.first + fx[k];
                    int c = cell.first.second + fy[k];
                    int life_line = cell.second;
                    
                    if(isValid(r, c, grid) == false) continue;
                    
                    if(grid[r][c] == 1 && life_line>0 && visited[r][c].find(life_line-1) == visited[r][c].end()){
                        todo.push({{r, c}, life_line-1});
                        visited[r][c].insert(life_line-1);
                    }else if(grid[r][c] == 0 && visited[r][c].find(life_line) == visited[r][c].end()){
                        todo.push({{r, c}, life_line});
                        visited[r][c].insert(life_line);
                    }
                    
                    if(r == rows-1 && c == cols-1){
                        return steps;
                    }
                    
                }
                
            }
        }
        
        
        return -1;
    }
};