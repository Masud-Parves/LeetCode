class Solution {
private:
    int helper(int idx, string& s, vector<int>& DP){
        if(idx == s.size()){
            return 1;
        }
        int& cache = DP[idx];
        if(cache != -1){
            return cache;
        }
        if(s[idx] == '0') return cache = 0;
        
        cache = helper(idx+1, s, DP);
        if(idx<s.size()-1 && (s[idx]=='1' or s[idx]=='2' && s[idx+1]<'7') ){
            cache += helper(idx+2, s, DP);
        }
        
        return cache;
    }
public:
    int numDecodings(string s) {
        if(s[0]=='0' || s.size()==0) return 0;
        int n = s.size();
        vector<int> DP(n+1, -1);
        
        DP[n] = 1;
        for(int i=n-1; i>=0; i--){
            DP[i] = DP[i+1];
            if(i<s.size()-1 && (s[i]=='1' or s[i]=='2' && s[i+1]<'7') ){
                DP[i] += DP[i+2];
            }
            if(s[i] == '0') DP[i] = 0;
        }
        
        return DP[0];
    }
};