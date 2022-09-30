class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        
        int low = 0, high = n-1, pivot;
        
        while(low<high){
            pivot = low + (high-low)/2;
            
            if(nums[pivot]==nums[pivot+1]){
                int rightElements = n-pivot+2;
                if(rightElements%2==0) high = pivot-1;
                else low = pivot+2;
            } else if(nums[pivot-1] == nums[pivot]){
                int rightElements = n-pivot+1;
                if(rightElements%2==0) high = pivot-2;
                else low = pivot+1;
            } else return nums[pivot];
            
            
        }
        return nums[low];
    }
};