class Solution {
private:
    int helper(int idx, int prev, vector<int>& stones, unordered_map<int, int>& seen, vector<vector<int>>& DP, int n){
        if(seen[stones[idx]] == n-1){
            return 1;
        }

        int& cache = DP[idx][prev];
        if(cache != -1){
            return cache;
        }
        
        cache = 0;
        bool state = false;
        if(prev-1 != 0 && seen.find(stones[idx]+prev-1) != seen.end()){
            state |= helper(seen[stones[idx]+prev-1], prev-1, stones, seen, DP, n);
        }
        
        if(seen.find(stones[idx]+prev) != seen.end()){
            state |= helper(seen[stones[idx]+prev], prev, stones, seen, DP, n);
        }
        
        if(seen.find(stones[idx]+prev+1) != seen.end()){
            state |= helper(seen[stones[idx]+prev+1], prev+1, stones, seen, DP, n);
        }
        return cache = state;
    }
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        
        if(stones[0]+1<stones[1]) return false;
        
        unordered_map<int, int>seen;
        for(int i=0; i<n; i++){
            seen[stones[i]] = i;
        }
        vector<vector<int>> DP(n+1, vector<int>(n+1, -1));
        return helper(1, 1, stones, seen, DP, n);
    }
};