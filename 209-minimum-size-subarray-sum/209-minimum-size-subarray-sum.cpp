class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int window = INT_MAX;
        vector<int>prefixSum(n, 0);
        
        for(int i=0; i<n; i++){
            if(i==0){
                prefixSum[i] = nums[i];
            } else {
                prefixSum[i] = prefixSum[i-1] + nums[i];
            }
        }
        
        
        for(int r=n-1; r>=0 && prefixSum[r]>=target; r--){
            int upper = upper_bound(prefixSum.begin(), prefixSum.end(), prefixSum[r]-target) - prefixSum.begin();
            window = min(window, r-upper+1);
        }
        
        
        return window == INT_MAX ? 0 : window;
    }
};