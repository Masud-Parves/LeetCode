class Solution {
private:
    // Topic: Backtracking
    // TC : O(2^target*k), where k is avg length of each combination,
    // SC : O(k, x) where k is avg length of each combination and x is number of combination we can get as result
    
    void findCombination(int idx, int target, vector<int>& nums, vector<vector<int>>& result, vector<int>& comb){
        
        if(target == 0) {
            result.push_back(comb);
            return;
        }
        
        if(idx == nums.size()){
            return;
        }
        
        if(nums[idx]<=target) {
            comb.push_back(nums[idx]);
            findCombination(idx, target-nums[idx], nums, result, comb);
            comb.pop_back();
        }
        findCombination(idx+1, target, nums, result, comb);
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size() == 0) {
            return result;
        }
        vector<int>comb;
        findCombination(0, target, nums, result, comb);
        return result;
    }
};