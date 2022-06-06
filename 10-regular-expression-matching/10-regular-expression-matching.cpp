class Solution {
private:
    bool isMatchExpression(int i, int j, string& s, string& p, vector<vector<int>>& DP){
        
        if(i>=s.size() && j>=p.size()) {
            return true;
        }
        
        if(i<s.size() && j>=p.size()) {
            return false;
        }
        
        int &cache = DP[i][j];
        if(cache != -1) {
            return cache;
        }
        cache = 0;
        bool match = (i<s.size() && (s[i] == p[j] || p[j] == '.'));
        
        if(j+1<p.size() && p[j+1] == '*'){
            bool pick = match && isMatchExpression(i+1, j, s, p, DP);
            bool notPick = isMatchExpression(i, j+2, s, p, DP);
            return cache = pick || notPick;
        }
        
        if(match == true) {
            return cache = isMatchExpression(i+1, j+1, s, p, DP);
        }
        return cache;
        
    }
    
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> DP(n+1, vector<int>(m+1, -1));
        return isMatchExpression(0, 0, s, p, DP);
    }
};