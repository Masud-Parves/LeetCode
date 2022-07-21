class Solution {
private:
    int helper(int idx, int prev, vector<int>& stones, unordered_map<int, int>& mp, vector<vector<int>>& DP){
        if(mp[stones[idx]] == stones.size()-1){
            return 1;
        }

        int& cache = DP[idx][prev];
        if(cache != -1){
            return cache;
        }
        
        cache = 0;
        bool tmp = false;
        if(prev-1 != 0 && mp.find(stones[idx]+prev-1) != mp.end()){
            tmp |= helper(mp[stones[idx]+prev-1], prev-1, stones, mp, DP);
        }
        
        if(mp.find(stones[idx]+prev) != mp.end()){
            tmp |= helper(mp[stones[idx]+prev], prev, stones, mp, DP);
        }
        
        if(mp.find(stones[idx]+prev+1) != mp.end()){
            tmp |= helper(mp[stones[idx]+prev+1], prev+1, stones, mp, DP);
        }
        return cache = tmp;
    }
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        
        if(stones[0]+1<stones[1]) return false;
        
        unordered_map<int, int>mp;
        for(int i=0; i<n; i++){
            mp[stones[i]] = i;
        }
        vector<vector<int>> DP(n+1, vector<int>(n+1, -1));
        return helper(1, 1, stones, mp, DP);
    }
};