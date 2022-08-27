class Solution {
private:
    int missing(vector<int>& nums, int idx){
        return nums[idx]-nums[0]-idx;
    }
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        
        if(missing(nums, nums.size()-1)<k){
            return nums.back() + k-missing(nums, nums.size()-1);
        }
        
        int L = 0, R = n-1, mid;
        while(L<R){
            mid = L + (R-L)/2;
            int miss = missing(nums, mid);
            if(miss<k) L = mid+1;
            else R = mid;
        }
        return nums[L-1] + k - missing(nums, L-1);
    }
};