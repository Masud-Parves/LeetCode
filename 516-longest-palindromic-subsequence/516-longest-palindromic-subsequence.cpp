class Solution {
public:
    
    
    int calculateLCS(int id1, int id2, string& s1, string& s2, vector<vector<int>>& DP){
        if(id1< 0 || id2<0) return 0;

        int &ret = DP[id1][id2];
        if(ret != -1) return ret;
        
        if(s1[id1] == s2[id2]){
            return 1 + calculateLCS(id1-1, id2-1, s1, s2, DP);
        }
        
        return ret = max(calculateLCS(id1-1, id2, s1, s2, DP), calculateLCS(id1, id2-1, s1, s2, DP));
    }
    
    int getLCS(string& s1, string& s2){
        int n = s1.size(), m = s2.size();
        vector<vector<int>> DP (n, vector<int>(m, -1));
        return calculateLCS(n-1, m-1, s1, s2, DP);
    }
    
    
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s.begin(), s.end());
        return getLCS(s, s2);
    }
};