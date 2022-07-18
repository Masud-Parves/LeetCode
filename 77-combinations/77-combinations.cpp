class Solution {
private:
    void backtrack(int idx, int n, int k, vector<int>& path, vector<vector<int>>& result){
        if(k == path.size()){
            result.push_back(path);
            return;
        }
        
        for(int i=idx+1; i<=n; i++){
            path.push_back(i);
            backtrack(i, n, k, path, result);
            path.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int>path;
        backtrack(0, n, k, path, result);
        return result;
    }
};