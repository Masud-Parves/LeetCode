class Solution {
private:
    int fx[4] = {0, 0, -1, 1};
    int fy[4] = {1, -1, 0, 0};
    
    bool isValid(int r, int c, int rows, int cols){
        return (r>=0 && r<rows && c>=0 && c<cols);
    }
    
    void bfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, queue<pair<int, int>>& Q){
        while(!Q.empty()){
            int ur = Q.front().first;
            int uc = Q.front().second;
            Q.pop();
            
            for(int i=0; i<4; i++){
                int vr = ur + fx[i];
                int vc = uc + fy[i];
                if(isValid(vr, vc, heights.size(), heights[0].size()) == false) continue;
                if(heights[ur][uc]<=heights[vr][vc] && visited[vr][vc] == false){
                    visited[vr][vc] = true;
                    Q.push({vr, vc});
                }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<int>> points;
        if(rows == 0 && cols == 0) return points;
        
        vector<vector<bool>> pacificVisited(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlanticVisited(rows, vector<bool>(cols, false));
        
        queue<pair<int, int>>pacificQueue;
        queue<pair<int, int>>atlanticQueue;

        for(int r=0 ; r<rows ; r++){
            pacificQueue.push({r, 0});
            pacificVisited[r][0] = true;
            atlanticQueue.push({r, cols-1});
            atlanticVisited[r][cols-1] = true;
        }
        
        for(int c=0; c<cols ; c++){
            pacificQueue.push({0, c});
            pacificVisited[0][c] = true;
            atlanticQueue.push({rows-1, c});
            atlanticVisited[rows-1][c] = true;
        }
        
        bfs(heights, pacificVisited, pacificQueue);
        bfs(heights, atlanticVisited, atlanticQueue);
        
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(pacificVisited[r][c] == true && atlanticVisited[r][c] == true){
                    points.push_back({r, c});
                }
            }
        }
        return points;
    }
};