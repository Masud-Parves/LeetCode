class Solution {
private:
    bool helper(int i, string& s1, int j, string& s2, int k, string& s3, vector<vector<int>>& memo){
        
        if(i == s1.size()){
            int kId = k;
            for(int idx = j; idx<s2.size(); idx++){
                if(s2[idx] != s3[kId++]) return 0;
            }
            return kId == s3.size();
        }
        
        if(j == s2.size()){
            int kId = k;
            for(int idx = i; idx<s1.size(); idx++){
                if(s1[idx] != s3[kId++]) return 0;
            }
            return kId == s3.size();
        }

        if(memo[i][j]>=0) {
            return memo[i][j] == 1 ? true : false;
        }
        bool ans = false;
        if((s3[k] == s1[i] && helper(i+1, s1, j, s2, k+1, s3, memo)) ||
           (s3[k] == s2[j] && helper(i, s1, j+1, s2, k+1, s3, memo))) {
            ans = true;
        }
        memo[i][j] = ans ? 1 : 0;
        return ans;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), k = s3.size();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        return helper(0, s1, 0, s2, 0, s3, memo);
    }
};