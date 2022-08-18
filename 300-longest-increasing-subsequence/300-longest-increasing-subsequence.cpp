class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> DP(n+1, vector<int>(n+1, 0));

        for(int i=n-1; i>=0; i--){
        	for(int p=i-1; p>=-1; p--){
        		DP[i][p+1] = DP[i+1][p+1];
        		if(p == -1 || nums[p]<nums[i]){
        			DP[i][p+1] = max(DP[i][p+1], 1 + DP[i+1][i+1]); 
        		}
        	}
        }

        return DP[0][0];
    }
};