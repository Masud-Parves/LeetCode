class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int rows = board.size(), cols = board[0].size();
        int numOfBattleShips = 0;
        for(int r=0; r<rows ; r++){
            for(int c=0; c<cols; c++){
                if(board[r][c] == 'X' && (r==0 || board[r-1][c]!='X') && (c==0 || board[r][c-1] != 'X')){
                    numOfBattleShips++;
                }
            }
        }
        return numOfBattleShips;
    }
};