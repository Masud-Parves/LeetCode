class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        
        
        vector<int>rowValue(rows, 1), colValue(cols, 1);
        
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(matrix[r][c] == 0){
                    rowValue[r] = 0;
                    colValue[c] = 0;
                }
            }
        }
        
        
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(rowValue[r] == 0 || colValue[c] == 0){
                    matrix[r][c] = 0;
                }
            }
        }
        
    }
};