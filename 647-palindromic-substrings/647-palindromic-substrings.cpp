
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> DP(n+1, vector<bool>(n+1, false));
        int ans = n;
        
        for(int i=0; i<n ; i++) {
            DP[i][i] = true;
        }
        
        for(int i=0; i<n-1; i++) {
            DP[i][i+1] = (s[i] == s[i+1]);
            ans += DP[i][i+1];
        }
        
        for(int len=3; len<=n ; len++){
            for(int i=0, j = i+len-1; j<n ; i++, j++){
                DP[i][j] = DP[i+1][j-1] && (s[i] == s[j]);
                ans += DP[i][j];
            }
        }

        return ans;
    }
};