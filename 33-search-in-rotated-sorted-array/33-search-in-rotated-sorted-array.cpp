class Solution {
private:
    int findPivotElement(vector<int>& nums, int target, int start, int end){
        while(start < end){
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
        int peakIndex = findPivotElement(nums, target, start, end);
        //cout << peakIndex << endl;
        retIdx = binarySearch(nums, target, start, peakIndex);
        //cout << retIdx << endl;
        if(retIdx != -1) return retIdx;
        retIdx = binarySearch(nums, target, peakIndex+1, end);
        //cout << retIdx << endl;
        return retIdx;
    }
};