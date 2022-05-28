class Solution {
public:
    
    int calculateLIS(int now, int pre, vector<int>& nums, vector<vector<int>>& DP){
        if(now == nums.size()) return 0;
        
        int &cache = DP[now][pre+1];
        if(cache != -1){
            return cache;
        }
        
        cache = calculateLIS(now+1, pre, nums, DP);
        if(pre == -1 || nums[now] > nums[pre]){
            cache = max(cache, 1+calculateLIS(now+1, now, nums, DP));
        }
        return cache;
    }
    
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // recursion code 
        //vector<vector<int>> DP(n+1, vector<int>(n+1, -1));
        //int result = calculateLIS(0, -1, nums, DP);
        
        
        // Binary Search for Efficient LIS
        vector<int>result;
        
        for(int i=0; i<n; i++){
            int low_idx = lower_bound(result.begin(), result.end(), nums[i]) - result.begin();
            
            if(low_idx == result.size()){
                result.push_back(nums[i]);
            } else {
                result[low_idx] = nums[i];
            }
        }
        
        return result.size();
    }
};