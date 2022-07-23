class Solution {
private:
    int helper(int idx, vector<int>& DP){
        if(idx == 0 ){
            return 1;
        }
        
        if(idx == 1 || idx == 2){
            return idx;
        }
        
        int& cache = DP[idx];
        if(cache != -1){
            return cache;
        }
        
        int total = 0;
        for(int i=1; i<=idx; i++){
            int left = helper(i-1, DP);
            int right = helper(idx-i, DP);
            total += left*right;
        }
        
        return cache = total;
    }
public:
    int numTrees(int n) {
        vector<int>DP(n+1, -1);
        return helper(n, DP);
    }
};