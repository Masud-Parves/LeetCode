int DP[101][30][101][101];
class Solution {
public:
    string s1;
    int helper(int idx, int prevId, int len, int k){
        if(k<0) return 1e9;
        
        if(idx == s1.size()){
            return 0;
        }
        
        int& cache = DP[idx][prevId][len][k];
        if(cache != -1){
            return cache;
        }
        
        int del  = helper(idx+1, prevId, len, k-1);
        int keep = 0;
        if(s1[idx]-'a' == prevId){
            if(len == 1 || len == 9 || len == 99){
                keep += 1;
            }
            keep = keep + helper(idx+1, prevId, len+1, k);
        } else {
            keep = 1 + helper(idx+1, s1[idx]-'a', 1, k);
        }
        
        return cache = min(del, keep);
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        s1 = s;
        memset(DP, -1, sizeof(DP));
        return helper(0, 26, 0, k);
    }
};