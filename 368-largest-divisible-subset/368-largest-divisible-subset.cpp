class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> DP(n, 1), hash(n);
        int lastIdx = 0, maxi = 0;
        for(int i=0; i<n ; i++){
            hash[i] = i;
            for(int j=0; j<i ; j++){
                if(nums[i]%nums[j] == 0 && DP[i] < DP[j]+1){
                    DP[i] = DP[j]+1;
                    hash[i] = j;
                }    
            }
            if(maxi < DP[i]){
                maxi = DP[i];
                lastIdx = i;
            }
        }
        
        vector<int>result;
        result.push_back(nums[lastIdx]);
        while(hash[lastIdx]!=lastIdx){
            lastIdx = hash[lastIdx];
            result.push_back(nums[lastIdx]);
        }
        return result;
    }
};