class Solution {
public:
    
    int calculateDistinct(int idx1, int idx2, string& s, string& t, vector<vector<int>>& DP){
        
        // Base case
        if(idx2<0) return 1;
        if(idx1<0) return 0;
        
        int &cache = DP[idx1][idx2];
        if(cache != -1){
            return cache;
        }

        cache = calculateDistinct(idx1-1, idx2, s, t, DP);
        if(s[idx1] == t[idx2]) {
            cache += calculateDistinct(idx1-1, idx2-1, s, t, DP);
        }
        return cache;
    }
    
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        vector<vector<int>> DP(n, vector<int>(m, -1));        
        int result = calculateDistinct(n-1, m-1, s, t, DP);
        return result;
    }
};