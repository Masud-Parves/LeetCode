class Solution {
private:
    int fx[4] = {1, -1, 0, 0};
    int fy[4] = {0, 0, -1, 1};
    
    bool isValid(int r, int c, vector<vector<int>>& isWater){
        return (r>=0 && r<isWater.size() && c>=0 && c<isWater[0].size());
    }
    
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rows = isWater.size(), cols = isWater[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        int height = 0;
        queue<pair<int, int>> todo;
        
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols ; c++){
                if(isWater[r][c] == 1){
                    todo.push({r, c});
                    visited[r][c] = true;
                    isWater[r][c] = height;
                }
            }
        }
        
        while(!todo.empty()){
            int size = todo.size();
            height++;
            cout << size << endl;
            for(int i=0; i<size; i++){
                auto cell = todo.front();
                todo.pop();
                int x = cell.first;
                int y = cell.second;
                for(int k=0; k<4; k++){
                    int rIdx = x+fx[k];
                    int cIdx = y+fy[k];
                    
                    if(isValid(rIdx, cIdx, isWater) == true && visited[rIdx][cIdx] == false){
                        isWater[rIdx][cIdx] = height;
                        visited[rIdx][cIdx] = true;
                        todo.push({rIdx, cIdx});
                    }
                }
            }
        }
        return isWater;
        
    }
};