class Solution {
public:
    
    
    // 5 6 7 8 0 1 2 3 4
    //              ^
    int search(vector<int>& nums, int target) {
        int n = nums.size();
                 
        int left = 0, right = n-1, mid;
        while(left<=right){
            mid = left + (right-left)/2;
            if(nums[mid] == target) return mid;
            
            if(nums[left]<=nums[mid]){
                if(nums[left]<=target && target<=nums[mid]){
                    right = mid-1;
                } else {
                    left = mid+1;
                }
            } else {
                if(target>=nums[mid] && target<=nums[right]){
                    left = mid+1;
                } else {
                    right = mid-1;
                }
            }
        }
        return -1;
    }
};