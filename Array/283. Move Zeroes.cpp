class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()==0)return;
        int leftMostZero = 0;
        for(int i=0 ; i<(int)nums.size(); i++){
            if(nums[i]){
                swap(nums[i], nums[leftMostZero++]);
            }
        }
    }
};