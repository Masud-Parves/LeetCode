
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> DP(n+1, vector<bool>(n+1, false));
        int ans = 0;
        for(int i=0; i<n ; i++){
            for(int start = 0, end = i; end<n ; start++, end++){
                
                if(s[start] == s[end]){
                    if(end-start<2 || DP[start+1][end-1] == true){
                        DP[start][end] = true;
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};