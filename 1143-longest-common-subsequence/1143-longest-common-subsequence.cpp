class Solution {
public:
    
    int maxLen(int idx1, int idx2, string& s1, string& s2, vector<vector<int>>& DP){
        
        if(idx1 <0 || idx2<0) return 0;
        
        int &cache = DP[idx1][idx2];
        if(cache != -1){
            return cache;
        }
        
        cache = 0;
        
        if(s1[idx1] == s2[idx2]){
            cache = 1 + maxLen(idx1-1, idx2-1, s1, s2, DP);
        } else {
            cache = max(maxLen(idx1-1, idx2, s1, s2, DP), maxLen(idx1, idx2-1, s1, s2, DP)); 
        }
        
        return cache;
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<int>previousRow(m+1, 0), currentRow(m+1, 0); 

        // Time : O(n*m)        
        // Space Optimization, O(n+m)

        for(int idx2 = 0; idx2<=m; idx2++){
            previousRow[idx2] = 0;
        }
        
        for(int idx1 = 1; idx1<=n ; idx1++){
            for(int idx2 = 1; idx2<=m ; idx2++){
                if(text1[idx1-1] == text2[idx2-1]){ // shifing index for base case;
                    currentRow[idx2] = 1 + previousRow[idx2-1];
                } else {
                    currentRow[idx2] = max(previousRow[idx2], currentRow[idx2-1]);
                }
            }
            previousRow = currentRow;
        }
        
        return previousRow[m];
    }
};