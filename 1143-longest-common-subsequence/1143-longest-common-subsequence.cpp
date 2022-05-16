class Solution {
public:
    
    int maxLen(int idx1, int idx2, string& s1, string& s2, vector<vector<int>>& DP){
        
        if(idx1 <0 || idx2<0) return 0;
        if(idx1 == 0 && idx2 ==0) return s1[idx1]==s2[idx2];
        
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
        int len1 = text1.size(), len2 = text2.size();
        
        vector<vector<int>>DP(len1, vector<int>(len2, -1));
        
        return maxLen(len1-1, len2-1, text1, text2, DP);
    }
};