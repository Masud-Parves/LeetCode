class Solution {
private:
    void generatePermutation(vector<int>& nums, vector<int>& perm, unordered_map<int, bool>& taken,
                             vector<vector<int>>& result){
        if(perm.size() == nums.size()){
            result.push_back(perm);
            return;
        }
        
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(taken[nums[i]] == false){
                taken[nums[i]] = true;
                perm.push_back(nums[i]);
                generatePermutation(nums, perm, taken, result);
                perm.pop_back();
                taken[nums[i]] = false;
            }
        }
        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {

        if(nums.size() == 1){
            return {{nums[0]}};
        }
        vector<vector<int>> result;
        vector<int>perm;
        unordered_map<int, bool>taken;
        generatePermutation(nums, perm, taken, result);
        return result;
    }
};