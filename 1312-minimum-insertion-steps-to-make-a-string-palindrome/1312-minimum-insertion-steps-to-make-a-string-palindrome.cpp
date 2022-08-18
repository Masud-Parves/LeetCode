class Solution {
private: 
    int getLCS(string& s1, string& s2){
        int n = s1.size(), m = s2.size();
	    vector<vector<int>> DP (n+1, vector<int>(m+1, 0));
	    
	    for(int i=1; i<=n; i++){
	        for(int j=1; j<=m; j++){
	            if(s1[i-1] == s2[j-1]){
	                DP[i][j] = 1 + DP[i-1][j-1];
	            } else {
	                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
	            }
	        }
	    }
	    return DP[n][m];
    }
public:
    int minInsertions(string s) {
        string s2 = s;
        reverse(s.begin(), s.end());
        return s.size() - getLCS(s, s2);
    }
};