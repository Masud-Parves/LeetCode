class Solution {
private:
    bool window_sliding(vector<int>& nums, int window, int target){
        int window_sum = 0;
        int n = nums.size();
        int l = 0, r = 0;
        while(r<window){
            window_sum += nums[r];
            r++;
        }
        if(window_sum>=target) return true;
        for(int r=window; r<n; r++){
            window_sum += nums[r];
            window_sum -= nums[l];
            l++;
            if(window_sum>=target) return true;
            
        }
        return false;
    }
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int window = INT_MAX;
        int l = 0, r = nums.size();
        
        while(l<=r){
            int mid = l + (r-l)/2;
            if(window_sliding(nums, mid, target)){
                r = mid-1;
                window = mid;
            } else {
                l = mid+1;
            }
        }
        return window == INT_MAX ? 0 : window;
    }
};