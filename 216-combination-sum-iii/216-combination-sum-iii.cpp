class Solution {
private:
    void getAllCombination(int target, int k, vector<int>& combo, vector<vector<int>>& result){
        if(k == combo.size() && target == 0){
            result.push_back(combo);
            return;
        }
        
        if(combo.size()<k){
            for(int i=(combo.empty()? 1 : combo.back()+1); i<=9; i++){
                combo.push_back(i);
                getAllCombination(target-i, k, combo, result);
                combo.pop_back();
            }  
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        if(n>45) return result;
        vector<int>combo;
        getAllCombination(n, k, combo, result);
        return result;
    }
};