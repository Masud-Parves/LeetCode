class Solution {
private:
    int helper(int idx, int n, vector<int>& arr, int k, vector<int>& DP){
        if(idx == n){
            return 0;
        }
        
        int& cache = DP[idx];
        if(cache != -1){
            return cache;
        }
        cache = INT_MIN;
        int current = 0, currLen = 0, maxVal = INT_MIN;
        for(int i=idx ; i<min(idx+k, n); i++){
            currLen++;
            maxVal = max(maxVal, arr[i]);
            int cost = (maxVal*currLen) + helper(i+1, n, arr, k, DP);
            cache = max(cache, cost);
        }
        return cache;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>DP(n, -1);
        return helper(0, n, arr, k, DP);
    }
};