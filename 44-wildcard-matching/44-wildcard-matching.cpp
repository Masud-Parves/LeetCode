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
        vector<vector<bool>> DP(n+1, vector<bool>(m+1, false));
		for (int j = 0; j < p.size() && p[j] == '*'; ++j) {
            DP[0][j + 1] = true;
        }

        DP[0][0] = true;
        for(int i=0; i< m; i++){
            if(p[i] == '*') {
            	DP[0][i+1] = true;
            } else break;
        }


        for(int i=1; i<=n ; i++){
        	for(int j=1; j<=m; j++){
        		if(s[i-1] == p[j-1] || p[j-1] == '?') {
        			DP[i][j] = DP[i-1][j-1];
        		}else if(p[j-1] == '*') {
        			DP[i][j] = DP[i-1][j] | DP[i][j-1];
        		}
        	}
        }


        return DP[n][m];
    }
};