class Solution {
public:
    void sortColors(vector<int>& nums) {
        int currIdx = 0, leftIdx = 0, rightIdx = nums.size()-1;
        while(currIdx<=rightIdx){
            if(nums[currIdx] == 2){
                swap(nums[currIdx], nums[rightIdx]);
                rightIdx--;
            } else if(nums[currIdx] == 0){
                swap(nums[leftIdx], nums[currIdx]);
                leftIdx++;
                currIdx++;
            } else currIdx++;
        }
    }
};