class Solution {
private:
    int fx[4] = {1, -1, 0, 0};
    int fy[4] = {0, 0, 1, -1};
    
    
    bool isValid(int r, int c, vector<string>& grid){
        return (r>=0 && r<grid.size() && c>=0 && c<grid[0].size() && grid[r][c] != '#');
    }
    bool isKey(int r, int c, vector<string>& grid, string& curr_state, int& curr_key){
        if(grid[r][c]<96){
            // lock
            int key_id = grid[r][c] -'A';
            if(curr_state[key_id] == '1'){
                return true;
            }
            return false;
            
        } else {
            // key
            int key_id = grid[r][c] - 'a';
            if(curr_state[key_id] != '1'){
                curr_state[key_id] = '1';
                curr_key++;
            }
            return true;
        }
    }
    
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<unordered_set<string>>> visited(rows, vector<unordered_set<string>>(cols, unordered_set<string>{}));
        
        queue<pair<pair<int, int>, pair<string, int>>>todo;
        
        string state(26, '.');
        int keys=0;
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c] == '@'){
                    todo.push({{r, c}, {state, 0}});
                    grid[r][c] = '.';
                    visited[r][c].insert(state);
                }
                if(grid[r][c] !='#' && grid[r][c] != '.'){
                   keys++; 
                }
            }
        }
        keys /= 2;
       
        int steps = 0;
        while(!todo.empty()){
            int size = todo.size();
            
            steps++;
            for(int i=0; i<size; i++){
                auto cell = todo.front();
                todo.pop();
                for(int k=0; k<4; k++){
                    int r = cell.first.first + fx[k];
                    int c = cell.first.second + fy[k];
                    string curr_state = cell.second.first;
                    int curr_key = cell.second.second;
                    //cout << "pass boundary" << endl;
                    if(!isValid(r, c, grid)) continue;
                   
                    if(grid[r][c] != '.' && isKey(r, c, grid, curr_state, curr_key) == false) continue;
                    if(visited[r][c].find(curr_state) != visited[r][c].end()) continue;
                    
                    visited[r][c].insert(curr_state);
                    todo.push({{r, c}, {curr_state, curr_key}});
                    //cout << curr_key << endl;
                    if(curr_key == keys){
                        return steps;
                    }
                }
            }
            
        }

        return -1;
    }
};