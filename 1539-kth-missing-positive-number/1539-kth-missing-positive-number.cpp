class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int low = 0, high = nums.size()-1, mid;
        
        while(low<=high){
            mid = low + (high-low)/2;
            
            int currCount = nums[mid] - mid -1;
            if(currCount < k){
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return k + low;
    }
};