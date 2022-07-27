class Solution {
private:
    void backtrack(int idx, vector<int>& nums, vector<int>& combo, set<vector<int>>& result){
        if(idx == nums.size()){
            if(combo.size()>1)
                result.insert(combo);
            return;
        }
        
        
        backtrack(idx+1, nums, combo, result);
        if(combo.empty() || combo.back()<=nums[idx]){
            combo.push_back(nums[idx]);
            backtrack(idx+1, nums, combo, result);
            combo.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size()==0){
            return result;
        }
        vector<int>combo;
        set<vector<int>> ret;
        backtrack(0, nums, combo, ret);
        for(auto& v : ret){
            result.push_back(v);
        }
        return result;
    }
};