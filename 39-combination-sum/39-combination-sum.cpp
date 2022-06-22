class Solution {
private:
    void getAllCombination(int idx, vector<int>& candidates, int target, vector<vector<int>>& result,
                          vector<int>& comb, int currSum){
        int n = candidates.size();

        if(currSum == target){
            result.push_back(comb);
            return;
        }
        
        if(idx == n){
            return;
        }
        
        
        if(currSum + candidates[idx]<=target){
            comb.push_back(candidates[idx]);
            getAllCombination(idx, candidates, target, result, comb, currSum+candidates[idx]);
            comb.pop_back();
        }

        getAllCombination(idx+1, candidates, target, result, comb, currSum);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int>comb;
        getAllCombination(0, candidates, target, result, comb, 0);
        return result;
    }
};