class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        sort(nums.begin(), nums.end());
        
        for(int r = n-1; r>=2 ;r--){
            int low=0, high=r-1;
            while(low<high){
                if(nums[low]+nums[high]>nums[r]) {
                    result += (high-low);
                    high--;
                }
                else low++;
            }
        }
        return result;
    }
};