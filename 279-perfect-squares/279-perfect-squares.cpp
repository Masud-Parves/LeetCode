class Solution {
private:
    int helper(int idx, int target, vector<int>& nums, vector<vector<int>>& DP){
        if(target == 0){
            return 0;
        }
        if(idx == nums.size()){
            return INT_MAX/2;
        }
        
        int& cache = DP[idx][target];
        if(cache != -1){
            return cache;
        }
        
        int way1 = 0, way2 = INT_MAX;
        way1 = helper(idx+1, target, nums, DP);
        if(target>=nums[idx]){
            way2 = 1 + helper(idx, target-nums[idx], nums, DP);
        }
        return cache = min(way1, way2);
    }
public:
    int numSquares(int n) {
        if(n == 1) return 1;
        vector<int>nums;
        int i = 1;
        while(i*i<=n){
            nums.push_back(i*i);
            i++;
        }
        int idx = nums.size();
        vector<vector<int>> DP(idx+1, vector<int>(n+1, -1));
        return helper(0, n, nums, DP);
    }
};