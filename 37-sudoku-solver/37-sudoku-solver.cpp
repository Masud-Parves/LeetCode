class Solution {
private:
    bool isValid(int r, int c, char ch, vector<vector<char>>& board){

        for(int i=0; i<9; i++){
            if(board[i][c] == ch){
                return false;
            }
            if(board[r][i] == ch){
                return false;
            }
            int row_idx = 3*(r/3)+(i/3), col_idx = 3*(c/3) + (i%3);
            if(board[row_idx][col_idx] == ch){
                return false;
            }
        }
        return true;
        
    }
    bool solver(vector<vector<char>>& board){
        int row = board.size(), col = board[0].size();
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(board[i][j] == '.'){
                    for(char c = '1' ; c<='9'; c++){
                        if(isValid(i, j, c, board)){
                            board[i][j] = c;
                            if(solver(board)){
                                return true;
                            } else {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        solver(board);
        return;
    }
};