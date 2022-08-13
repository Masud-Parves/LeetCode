class Solution {
private:
    int binarySearch(vector<int>& nums, int target, bool firstIndex){
        int index = -1;
        int L = 0, R = nums.size()-1;
        
        while(L<=R){
            int mid = L + (R-L)/2;
            if(target == nums[mid]){
                // may possible answer but still for better answer
                index = mid;
                if(firstIndex){
                    R = mid-1;
                } else {
                    L = mid +1;
                }
            } else if(nums[mid]>target) {
                R = mid-1;
            } else {
                L = mid + 1;
            }
        }
        return index;
    }
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> result;
        sort(nums.begin(), nums.end());
        int firstOccurrence = binarySearch(nums, target, true);
        if(firstOccurrence == -1) return result;
        
        int lastOccurrence = binarySearch(nums, target, false);
        for(int i=firstOccurrence ; i<=lastOccurrence; i++){
            result.push_back(i);
        }
        return result;
    }
};