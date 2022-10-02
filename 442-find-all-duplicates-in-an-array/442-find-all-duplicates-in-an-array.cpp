class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> duplicates;
        for(auto& x : nums){
            if(nums[abs(x)-1]<0){
                duplicates.push_back(abs(x));
            }
            nums[abs(x)-1] *=-1;
        }
        return duplicates;
    }
};