class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int>DP(n, 0);
        
        DP[0] = nums[0];
        
        for(int i=1; i<n; i++){
            DP[i] = max(DP[i-1] , nums[i] + ((i>1) ?  DP[i-2] : 0));
        }
        return DP[n-1];
    }
};