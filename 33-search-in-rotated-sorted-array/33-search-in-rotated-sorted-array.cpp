class Solution {
private:
    int findPivotElement(vector<int>& nums){
        int start = 0, end = nums.size()-1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(mid+1<=end && nums[mid]>nums[mid+1]) return mid;
            else if(mid-1>=start && nums[mid-1]>nums[mid]) return mid-1;
            else if(nums[start]>nums[mid]) {
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        return -1;
    }
    
    int binarySearch(vector<int>& nums, int target, int start, int end){
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid] == target){
                return mid;
            } else if(nums[mid]<target){
                start = mid+1;
            } else {
                end = mid-1;
            }
        }
        return -1;
    }
    
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        int retIdx = -1;
        int pivot = findPivotElement(nums);
        if(pivot == -1) return binarySearch(nums, target, 0, end);
        
        if(nums[pivot] == target) return pivot;
        
        if(target>=nums[0]) return binarySearch(nums, target, start, pivot-1);
        
        return binarySearch(nums, target, pivot+1, end);
    }
};