class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int>DP(n, 1), count(n, 1);
        int LIS = 0, result = 0;
        for(int idx = 0; idx<n ; idx++){
            for(int prev = 0; prev < idx ; prev++){
                if(nums[prev] < nums[idx] && DP[idx] < DP[prev]+1){
                    DP[idx] = DP[prev] + 1;
                    count[idx] = count[prev];
                } else if(nums[prev] < nums[idx] && DP[idx] == DP[prev]+1){
                    count[idx] += count[prev];
                }
            }
            LIS = max(LIS, DP[idx]);
        }
        
        for(int i=0; i<n ; i++){
            if(DP[i] == LIS){
                result += count[i];
            }
        }
        return result;
    }
};