class Solution {
private:
    int MOD=1000000007;
    int backtrack(int idx, char last , map<char, vector<char>>& seen, int n, vector<vector<int>>& DP){
        if(idx==n){
            return 1;
        }
        
        int& cache = DP[idx][last-'a'];
        if(cache != -1){
            return cache;
        }
        
        cache = 0;
        for(int i=0; i<seen[last].size(); i++){
            cache = (cache + backtrack(idx+1, seen[last][i], seen, n, DP))%MOD;
        }
        return cache;
    }
public:
    int countVowelPermutation(int n) {
    
        map<char, vector<char>> seen;
        seen['a']={'e'};
        seen['e']={'a','i'};
        seen['i']={'a','e','o','u'};
        seen['o']={'i','u'};
        seen['u']={'a'};
        seen['s']={'a','e','i','o','u'};
        
        vector<vector<int>>DP(n+1, vector<int>(26, -1));
        
        int ret = backtrack(0, 's', seen, n, DP);
        
        return ret;
    }
};