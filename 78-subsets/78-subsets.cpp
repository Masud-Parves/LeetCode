class Solution {
private:
    void getSubsets(int idx, vector<int>& nums, vector<int>& path, vector<vector<int>>& result){
        if(idx == nums.size()){
            result.push_back(path);
            return;
        }
        
        
        path.push_back(nums[idx]);
        getSubsets(idx+1, nums, path, result);
        path.pop_back();
        getSubsets(idx+1, nums, path, result);
        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size()==0){
            return result;
        }
        vector<int>path;
        getSubsets(0, nums, path, result);
        return result;
    }
};