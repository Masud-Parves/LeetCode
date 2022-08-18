class Solution {
private:
    int helper(int idx1, int idx2, string& s, string& p, vector<vector<int>>& DP){
        if(idx1<0 && idx2<0) return true;
        if(idx2<0) return false;
        if(idx1<0){
            for(int i=0; i<=idx2; i++){
                if(p[i] != '*') return false;
            }
            return true;
        }
        
        int& cache = DP[idx1][idx2];
        if(cache != -1){
            return cache;
        }
        
        cache = false;
        if(s[idx1] == p[idx2] || p[idx2] == '?'){
            return cache = helper(idx1-1, idx2-1, s, p, DP);
        }
        
        if(p[idx2] == '*') {
            cache = helper(idx1, idx2-1, s, p, DP) | helper(idx1-1, idx2, s, p, DP);
        }
        return cache;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> DP(n, vector<int>(m, -1));
        return helper(n-1, m-1, s, p, DP);
    }
};