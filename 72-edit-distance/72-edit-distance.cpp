class Solution {
public:
    
    int helper(int idx1, int idx2, string& word1, string& word2, vector<vector<int>>& DP){
        
        if(idx1==0){
            return idx2;
        }
        
        if(idx2 == 0){
            return idx1;
        }
        
        
        int &cache = DP[idx1][idx2];
        if(cache != -1){
            return cache;
        }
        
        
        if(word1[idx1-1] == word2[idx2-1]){
            cache = helper(idx1-1, idx2-1, word1, word2, DP);
        } else {
            cache = 1 + helper(idx1-1, idx2, word1, word2, DP); // deletion
            cache = min(cache , 1 + helper(idx1, idx2-1, word1, word2, DP)); // insertion
            cache = min(cache , 1 + helper(idx1-1, idx2-1, word1, word2, DP)); // replace
        }
        
        return cache;
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>DP(n+1, vector<int>(m+1,  INT_MAX/2));
        
        
        for(int idx1 = 0; idx1<=n; idx1++){
            DP[idx1][0] = idx1;
        }
        
        for(int idx2 = 0; idx2<=m; idx2++){
            DP[0][idx2] = idx2;
        }
        
        for(int i=1; i<=n ; i++){
            for(int j=1; j<=m ; j++){
                if(word1[i-1] == word2[j-1]){
                    DP[i][j] = DP[i-1][j-1];
                } else {
                    DP[i][j] = 1 + min(DP[i-1][j-1], min(DP[i-1][j], DP[i][j-1]));
                }
            }
        }
        
        return DP[n][m];
    }
};