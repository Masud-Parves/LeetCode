class Solution {
private:
    int fx[4] = {1, -1, 0, 0};
    int fy[4] = {0, 0, 1, -1};
    bool isValid(int r, int c, vector<vector<int>>& image, int color){
        return r>=0 && r<image.size() && c>=0 && c<image[0].size() && image[r][c] == color;
    }
    
    void dfs(int r, int c, vector<vector<int>>& image, vector<vector<bool>>& seen, int oldColor, int newColor){
        if(isValid(r, c, image, oldColor) == false || seen[r][c] == true) return;
        
        seen[r][c] = true;
        image[r][c] = newColor;
        for(int i=0; i<4; i++){
            int r_idx = r + fx[i];
            int c_idx = c + fy[i];
            dfs(r_idx, c_idx, image, seen, oldColor, newColor);
        }
        return;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size(), cols = image[0].size();
        vector<vector<bool>>seen(rows, vector<bool>(cols, false));
        dfs(sr, sc, image, seen, image[sr][sc], color);
        return image;
    }
};