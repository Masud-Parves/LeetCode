class Solution {
private:
    int calculateConsecutiveOne(int idx, int taken, vector<int>& nums, vector<vector<int>>& DP){
        
        if(idx == nums.size()) {
            return 0;
        }
        
        if(taken == 1 && nums[idx] == 0) {
            return 0;
        }
        
        int &cache = DP[idx][taken];
        if(cache != -1) {
            return cache;
        }
        
        cache = 0;
        if(nums[idx] == 0 && taken == 0){
            cache += 1 + calculateConsecutiveOne(idx+1, 1, nums, DP); 
        } else {
            cache += 1 + calculateConsecutiveOne(idx+1, taken, nums, DP);
        }
        
        return cache;
    }
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> DP(n, vector<int>(2, -1));
        //int result = calculateConsecutiveOne(0, 0, nums, DP);
        int ret = 0;
        for(int i=0; i<n; i++){
            ret = max(ret, calculateConsecutiveOne(i, 0, nums, DP));
        }
        
        // [1,0,1,1,0,1,0,1,1,1,1, 1, 1, 1, 1, 0, 0, 1]
        
        return ret;
    }
};