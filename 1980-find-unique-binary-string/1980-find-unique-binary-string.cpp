class Solution {
private:
    bool backtrack(int idx, int n, unordered_map<string, int>& seen, string& res, string& ans){
        if(idx == n){
            if(seen.find(res) == seen.end()){
                ans = res;
                return true;
            }
            return false;
        }
        
        
        res[idx] = '1';
        if(backtrack(idx+1, n, seen, res, ans)) return true;
        res[idx] = '0';
        
        return backtrack(idx+1, n, seen, res, ans);
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string result(n, '0');
        
        unordered_map<string, int> seen;
        for(auto& num : nums){
            seen[num]++;
        }
        
        if(seen.find(result) == seen.end()) return result;
        //cout << "case" << endl;
        string ans="";
        backtrack(0, n, seen, result, ans);
        return ans;
    }
};