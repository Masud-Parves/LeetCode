class Solution {
private:
    int rows, cols;
    void dfs(int r, int c, vector<vector<char>>& board){
        if(r<0 || r==rows || c<0 || c == cols || board[r][c] == '.'){
            return;
        }
        
        board[r][c] = '.';
        dfs(r+1, c, board);
        dfs(r, c+1, board);
    }
public:
    int countBattleships(vector<vector<char>>& board) {
        rows = board.size(), cols = board[0].size();
        int numOfBattleShips = 0;
        for(int r=0; r<rows ; r++){
            for(int c=0; c<cols; c++){
                if(board[r][c] == 'X'){
                    dfs(r, c, board);
                    numOfBattleShips++;
                }
            }
        }
        return numOfBattleShips;
    }
};