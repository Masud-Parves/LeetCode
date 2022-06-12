class Solution {
public:
    int search(vector<int>& nums, int target) {
        int L = 0, R = nums.size()-1;
        
        while(L<=R){
            int M = (L+R)/2;
            
            if(nums[M] == target){
                return M;
            }
            
            if(nums[L] <= nums[M]){
                // pivot not present in this segment
                if(nums[L]<=target && target<=nums[M]){
                    R = M - 1;
                } else {
                    L = M + 1;
                }
                
            } else {
                // pivot present in this segment
                
                if(nums[M]<=target && target<=nums[R]){
                    L = M + 1;
                } else {
                    R = M - 1;
                }
            }
            
        }
        return -1;
    }
};