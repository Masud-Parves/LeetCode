class Solution {
private:
    int fx[4] = {0, 0, 1, -1};
    int fy[4] = {1, -1, 0, 0};
    bool search(int r, int c, int idx, vector<vector<char>>& board, string& word){
        if(idx == word.size()){
            return true;
        }
        
        if(r<0 || r == board.size() || c<0 || c==board[0].size() || board[r][c] != word[idx]){
            return false;
        }
        
        board[r][c] = '#';
        
        for(int i=0 ; i<4; i++){
            int r_idx = r + fx[i];
            int c_idx = c + fy[i];
            int ret = search(r_idx, c_idx, idx+1, board, word);
            if(ret) return ret;
        }
        board[r][c] = word[idx];
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(), col = board[0].size();

        for(int i=0; i<row ; i++){
            for(int j=0; j<col; j++){
                if(word[0]==board[i][j]){
                    //cout << word[0] << endl;
                    if(search(i, j, 0, board, word)){
                        //cout << word[0] << endl;
                        return true;
                    }
                }
            }
        }
        return false;
    }
};