class Solution {
private:
    int helper(int idx, vector<int>& satisfaction, int time, vector<vector<int>>& cache){
        if(idx == satisfaction.size()){
            return 0;
        }
        
        int& currState = cache[idx][time];
        if(currState != -1){
            return currState;
        }
        
        int way1 = helper(idx+1, satisfaction, time, cache);
        int way2 = time*satisfaction[idx] + helper(idx+1, satisfaction, time+1, cache);
        return currState = max(way1, way2);
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> cache(n, vector<int>(n+1, -1));
        return helper(0, satisfaction, 1, cache);
    }
};