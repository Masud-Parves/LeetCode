class Solution {
private:
    int binarySearch(vector<int>& nums, int target, bool lookingFirstElement){
        int index = -1;
        int L = 0, R = nums.size()-1;
        
        while(L<=R){
            int mid = L + (R-L)/2;
            if(target == nums[mid]){
                index = mid;
                if(lookingFirstElement){
                    R = mid-1;
                } else {
                    L = mid +1;
                }
            } else if(target<nums[mid]){
                R = mid - 1;
            } else {
                L = mid + 1;
            }
        }
        return index;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2);
        result[0] = binarySearch(nums, target, true);
        result[1] = binarySearch(nums, target, false);
        return result;
    }
};