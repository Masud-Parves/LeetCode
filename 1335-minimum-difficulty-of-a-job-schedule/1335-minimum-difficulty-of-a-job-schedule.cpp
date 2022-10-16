class Solution {
private:
    int helper(int idx, int day, vector<int>& jobs, vector<vector<int>>& DP){
        int n = jobs.size();
        if(day == 1){
            int maxVal = 0;
            for(int i=idx; i<n; i++){
                maxVal = max(maxVal, jobs[i]);
            }
            return maxVal;
        }
        
        int& cache = DP[idx][day];
        if(cache != -1){
            return cache;
        }
        int maxVal = 0, maxProfit = INT_MAX;
        for(int i=idx; i<=n-day; i++){
            maxVal = max(maxVal, jobs[i]);
            int ret = helper(i+1, day-1, jobs, DP);
            maxProfit = min(maxProfit, ret + maxVal);
            
        }
        return cache = maxProfit;
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int jobs = jobDifficulty.size();
        if(jobs<d) {
            return -1;
        }
        vector<vector<int>> DP(jobs+1, vector<int>(d+1, -1));
        return helper(0, d, jobDifficulty, DP);
    }
};