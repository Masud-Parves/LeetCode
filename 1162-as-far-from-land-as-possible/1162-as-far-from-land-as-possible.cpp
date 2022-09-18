class Solution {
private:
    bool isValid(int r, int c, vector<vector<int>>& grid){
        return (r>=0 && r<grid.size() && c>=0 && c<grid[0].size());
    }
public:
    int maxDistance(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        if(rows == 0 && cols == 0) return -1;
        
        
        bool isPresentOne = false, isPresentZero = false;
        
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        
        queue<pair<int, int>> Q;
        for(int r=0; r<rows ; r++){
            for(int c=0; c<cols ; c++){
                if(grid[r][c] == 1){
                    dist[r][c] = 0;
                    Q.push({r, c});
                    isPresentOne = true;
                }
            }
        }
        if(isPresentOne == false) return -1;
        
        int fx[4] = {1, -1, 0, 0};
        int fy[4] = {0, 0, -1, 1};
        while(!Q.empty()){
            int ur = Q.front().first;
            int uc = Q.front().second;
            Q.pop();
            
            for(int i=0; i<4; i++){
                int vr = ur + fx[i];
                int vc = uc + fy[i];
                if(isValid(vc, vr, grid) == true && dist[vr][vc]>1+dist[ur][uc]){
                    dist[vr][vc] = dist[ur][uc]+1;
                    Q.push({vr, vc});
                    isPresentZero = true;
                }
            }
        }
        int maxDistance = 0;
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c] == 0 && dist[r][c] != INT_MAX){
                    maxDistance = max(maxDistance, dist[r][c]);
                }
            }
        }
        return isPresentZero == false ? -1 : maxDistance;
        
    }
};