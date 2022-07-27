class Solution {
private:
    int fx[4] = {0, 0, 1, -1};
    int fy[4] = {1, -1, 0, 0};
    bool search(int r, int c, int idx, vector<vector<char>>& board, string& word, vector<vector<bool>>& seen){
        if(idx == word.size()){
            return true;
        }
        
        if(r<0 || r == board.size() || c<0 || c==board[0].size() || seen[r][c] == true || board[r][c] != word[idx]){
            return false;
        }
        
        seen[r][c] = true;
        
        for(int i=0 ; i<4; i++){
            int r_idx = r + fx[i];
            int c_idx = c + fy[i];
            int ret = search(r_idx, c_idx, idx+1, board, word, seen);
            if(ret) return ret;
        }
        seen[r][c] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(), col = board[0].size();
        
        vector<vector<bool>>seen(row, vector<bool>(col, false));
        for(int i=0; i<row ; i++){
            for(int j=0; j<col; j++){
                if(word[0]==board[i][j]){
                    //cout << word[0] << endl;
                    if(search(i, j, 0, board, word, seen)){
                        cout << word[0] << endl;
                        return true;
                    }
                }
            }
        }
        return false;
    }
};