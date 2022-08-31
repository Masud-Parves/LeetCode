class Solution {
private:
    int helper(int L, int R, vector<int>& nums, vector<vector<int>>& DP){
        if(L>R) return 0;
        
        int& cache = DP[L][R];
        if(cache != -1){
            return cache;
        }
        
        int maximumCoins = INT_MIN;
        for(int k=L ; k<=R; k++){
            int pCoins = (L==0) ? 1 : nums[L-1];
            int nCoins = (R==nums.size()-1) ? 1 : nums[R+1];
            int coins = pCoins*nums[k]*nCoins + helper(L, k-1, nums, DP) + helper(k+1, R, nums, DP);
            maximumCoins = max(maximumCoins, coins);
        }
        return cache = maximumCoins;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> DP(n, vector<int>(n, -1));
        return helper(0, n-1, nums, DP);
    }
};