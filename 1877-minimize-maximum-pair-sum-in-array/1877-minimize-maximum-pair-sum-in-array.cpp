class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int minimized = 0;
        for(int i=0; i<n/2; i++){
            int currSum = nums[i] + nums[n-i-1];
            minimized = max(minimized, currSum);
        }
        return minimized;
    }
};