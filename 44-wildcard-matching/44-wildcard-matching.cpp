class Solution {
public:
    
    bool isWildcardMatching(int idx1, string& s, int idx2, string& p, vector<vector<int>>& DP){
        
        
        if(idx1<0 && idx2<0) return true;
        
        if(idx2<0) return false;
        
        if(idx1<0){
            for(int i=0; i<=idx2 ; i++){
                if(p[i] != '*'){
                    return false;
                }
            }
            return true;
        }
        
        int &cache = DP[idx1][idx2];
        if(cache != -1) return cache;
        
        if(s[idx1] == p[idx2] || p[idx2] == '?'){
            return cache = isWildcardMatching(idx1-1, s, idx2-1, p, DP);
        }
        
        if(p[idx2] == '*'){
            cache = isWildcardMatching(idx1, s, idx2-1, p, DP) | isWildcardMatching(idx1-1, s, idx2, p, DP);
        } else {
            cache = false;
        }
        
        return cache;
    }
    
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        vector<vector<int>> DP(n, vector<int>(m, -1));
        return isWildcardMatching(n-1, s, m-1, p, DP);
    }
};