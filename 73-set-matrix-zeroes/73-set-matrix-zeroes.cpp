class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        bool firstRow = false, firstCol= false;
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(r == 0 && matrix[r][c] == 0) firstRow = true;
                if(c == 0 && matrix[r][c] == 0) firstCol = true;
                if(matrix[r][c] == 0){
                    matrix[0][c] = 0;
                    matrix[r][0] = 0;
                }
            }
        }
        
        
        for(int r=1; r<rows; r++){
            for(int c=1; c<cols; c++){
                if(matrix[0][c] == 0 || matrix[r][0] == 0){
                    matrix[r][c] = 0;
                }
            }
        }
        if(firstRow) {
            for(int c = 0; c<cols; c++){
                matrix[0][c] = 0;    
            }
        }
        
        if(firstCol){
            for(int r = 0; r<rows; r++){
                matrix[r][0] = 0;    
            }
        }
    }
};