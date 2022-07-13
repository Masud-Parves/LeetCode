class Solution {
private:
    void getSubset(int idx, vector<int>& nums, vector<int>& subs, vector<vector<int>>& result){
        if(idx == nums.size()){
            result.push_back(subs);
            return;
        }
        
        getSubset(idx+1, nums, subs, result);
        subs.push_back(nums[idx]);
        getSubset(idx+1, nums, subs, result);
        subs.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() == 0) {
            return result;
        }
        vector<int>subs;
        getSubset(0, nums, subs, result);
        return result;
    }
};