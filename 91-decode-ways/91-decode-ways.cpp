class Solution {
private:
    int getNumberOfDecodings(int idx, string& s, vector<int>& DP){
        if(idx == s.size()){
            return 1;
        }
        
        int& cache = DP[idx];
        if(cache != -1){
            return cache;
        }
        
        if(s[idx] == '0') return cache = 0;
        cache = getNumberOfDecodings(idx+1, s, DP);
        if(idx<s.size()-1 && (s[idx]=='1' or s[idx]=='2' && s[idx+1]<'7') ){
            cache += getNumberOfDecodings(idx+2, s, DP);
        }
        return cache;
    }
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> DP(n+1, -1);
        return getNumberOfDecodings(0, s, DP);
    }
};