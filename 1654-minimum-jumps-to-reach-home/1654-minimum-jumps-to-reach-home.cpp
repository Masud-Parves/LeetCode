class Solution {
private:
    int helper(int currIdx, int dest, int isBackPossible, int forword, int backword, unordered_map<int, int>& seen, vector<vector<int>>& DP){
        if(currIdx == dest){
            return 0;
        }
        
        if(currIdx<0 || currIdx>6000 || seen.find(currIdx)!=seen.end()){
            return INT_MAX/2;
        }
        int& cache = DP[currIdx][isBackPossible];
        if(cache != -1){
            return cache;
        }
        
        cache = 1 + helper(currIdx+forword, dest, 1, forword, backword, seen, DP);
        
        if(isBackPossible == 1){
            cache = min(cache, 1 + helper(currIdx-backword, dest, 0, forword, backword, seen, DP));
        }
        return cache;
    }
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_map<int, int> seen;
        for(auto& val : forbidden){
            seen[val]++;
        }
        vector<vector<int>> DP(7001, vector<int>(2, -1));
        int result = helper(0, x, 1, a, b, seen, DP);
        return (result >= INT_MAX/2) ? -1 : result;
    }
};