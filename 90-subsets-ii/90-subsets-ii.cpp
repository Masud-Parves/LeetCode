class Solution {
private:
    void getSubsetWithDup(int idx, vector<int>& nums, vector<int>& subset, 
                          vector<vector<int>>& result){
        if(idx == nums.size()){
            result.push_back(subset);
            return;
        }
        
        
        // take the nums[i] element
        subset.push_back(nums[idx]);
        getSubsetWithDup(idx+1, nums, subset, result);
        subset.pop_back();
        
        // not take the element;
        int i = idx;
        while(i+1<nums.size() && nums[i] == nums[i+1]){
            i++;
        }
        getSubsetWithDup(i+1, nums, subset, result);
        
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() == 0) {
            return result;
        }
        sort(nums.begin(), nums.end());
        vector<int>subset;
        getSubsetWithDup(0, nums, subset, result);
        return result;
    }
};