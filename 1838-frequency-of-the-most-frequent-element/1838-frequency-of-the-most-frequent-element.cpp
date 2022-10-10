class Solution {
public:
    int maxFrequency(vector<int>& nums, int budget) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int maxFreq = 0;
        
        int l=0;
        long long prefix = budget;
        for(int r=0; r<n; r++){
            prefix += nums[r];
            int rangeCount = r-l+1;
            long long total = rangeCount*1LL*nums[r];
            if(prefix < total){
                while(prefix<total){
                    prefix -= nums[l++];
                    total -= nums[r];
                    rangeCount--;
                }
            }
            maxFreq = max(maxFreq, rangeCount);
        }
        
        return maxFreq;
    }
};