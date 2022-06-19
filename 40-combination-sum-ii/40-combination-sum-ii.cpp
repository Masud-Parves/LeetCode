class Solution {
private:
    // Topic : Backtracking
    // TC : O(2^n), where n is number of candidates.
    // SC : O(n) because we use currComb to keep track current combination and another O(n) for recursion stack memory.
    
    void findCombinations(int pos, vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& currComb){
        if(target == 0) {
            result.push_back(currComb);
            return;
        }
        
        if(target<0){
            return;
        }
        
        int prev = -1;
        for(int i=pos; i<candidates.size(); i++){
            if(prev == candidates[i]) continue;
            currComb.push_back(candidates[i]);
            findCombinations(i+1, candidates, target-candidates[i], result, currComb);
            currComb.pop_back();
            prev = candidates[i];
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int>currComb;
        findCombinations(0, candidates, target, result, currComb);
        return result;
    }
};