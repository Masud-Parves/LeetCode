class Solution {
private:
    int helper(int idx, int N, vector<int>&nums, vector<int>& DP){
        if(idx == N){
            return nums[idx];
        }
        if(idx<N) return 0;
        
        int& cache = DP[idx];
        if(cache != -1){
            return cache;
        }
        
        int way1 = helper(idx-1, N, nums, DP);
        int way2 = nums[idx] + helper(idx-2, N, nums, DP);
        
        return cache = max(way1, way2);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        
        vector<int>DP(n, -1);
        int way1 = helper(n-2, 0, nums, DP);
        fill(DP.begin(), DP.end(), -1);
        int way2 = helper(n-1, 1, nums, DP);    
        return max(way1, way2);
    }
};