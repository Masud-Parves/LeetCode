class Solution {
private:
    int helper(int idx, int taken, vector<int>& nums, vector<vector<int>>& DP){
        if(idx == 0){
            if(taken == 0) return nums[idx];
            return 0;
        }
        
        int& cache = DP[idx][taken];
        if(cache != -1){
            return cache;
        }
        
        int take = 0, not_take = 0;
        
        
        
        not_take = helper(idx-1, 0, nums, DP);
        if(taken == 0) {
            take = nums[idx] + helper(idx-1, 1-taken, nums, DP);
        }
        return cache = max(not_take, take);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<vector<int>>DP(n, vector<int>(2, -1));
        return helper(n-1, 0, nums, DP);
    }
};