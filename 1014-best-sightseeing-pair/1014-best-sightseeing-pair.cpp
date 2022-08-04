class Solution {
private:
    int helper(int idx, int take, vector<int>& values, vector<vector<int>>& memo){
        
        if(take >= 2) return 0;
        if(idx>=values.size()) {
            return INT_MIN;
        }
        
        int& cache = memo[idx][take];
        if(cache != -1){
            return cache;
        }
        
        int way1 = 0, way2 = 0;
        
        way1 = values[idx] + helper(idx+1, take+1, values, memo);
        way2 = helper(idx+1, take, values, memo);
        
        
        if(take == 1){
            way1 = way1-idx;
        } else {
            way1 += idx;
        }
        
        return cache = max(way1 , way2);
    }
public:
    // need to fina a pair with maximum value under the given conditions.
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<vector<int>>memo(n, vector<int>(3, -1));
        return helper(0, 0, values, memo);
    }
};