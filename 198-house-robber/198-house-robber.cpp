class Solution {
private:
    int helper(int idx, vector<int>& nums, vector<int>& DP){
        if(idx == 0){
            return nums[0];
        }
        if(idx<0) return 0;
        
        int& cache = DP[idx];
        if(cache != -1){
            return cache;
        }
        
        int take = 0, not_take = 0;

        not_take = helper(idx-1, nums, DP);
    
        take = nums[idx] + helper(idx-2, nums, DP);
        
        return cache = max(not_take, take);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int>DP(n, -1);
        return helper(n-1, nums, DP);
    }
};