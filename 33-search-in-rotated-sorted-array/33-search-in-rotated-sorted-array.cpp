class Solution {
private:
    int helper(vector<int>& nums, int target, int L, int R){
        int M = (L+R)/2;
        
        if(nums[M] == target) {
            return M;
        }
        
        if(L>R) return -1;
        
        if(nums[L]<=nums[M]){
            if(nums[L]<=target && target<=nums[M]){
                return helper(nums, target, L, M-1);
            } else {
                return helper(nums, target, M+1, R);
            }
        } else {
            if(nums[M]<=target && target<=nums[R]){
                return helper(nums, target, M+1, R);
            }else {
                return helper(nums, target, L, M-1);
            }
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int L = 0, R = nums.size()-1;
        
        return helper(nums, target, L, R);
    }
};