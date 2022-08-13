class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int index = -1;
        int L = 0, R = nums.size()-1;
        
        while(L<=R){
            int mid = L + (R-L)/2;
            if(nums[mid]<nums[mid+1]){
                index = mid+1;
                L = mid+1;
            } else if(nums[mid] > nums[mid+1]){
                index = mid;
                R = mid-1;
            }
        }
        return index;
    }
};