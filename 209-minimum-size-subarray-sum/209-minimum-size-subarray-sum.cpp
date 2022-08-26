class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int windowSum = 0, window = INT_MAX;
        while(r<n){
            windowSum += nums[r];
            while(windowSum>=target){
                window = min(window, r-l+1);
                windowSum -= nums[l];
                l++;
            }
            r++;
        }
        return window == INT_MAX ? 0 : window;
    }
};