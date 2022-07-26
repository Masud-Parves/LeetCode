class Solution {
private:
    void getCombinations(int idx, string& digits, vector<string>& latter, string& path, vector<string>& result){
        if(idx == digits.size()){
            result.push_back(path);
            return;
        }
        
        
        for(char ch : latter[digits[idx]-'0']){
            path.push_back(ch);
            getCombinations(idx+1, digits, latter, path, result);
            path.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.size()==0){
            return result;
        }
        vector<string> latter({"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"});
        string path="";
        getCombinations(0, digits, latter, path, result);
        return result;
    }
};