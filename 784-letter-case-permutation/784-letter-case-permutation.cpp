class Solution {
private:
    void helper(int idx, string& s, string& str, vector<string>& result){
        if(idx == s.size()){
            result.push_back(str);
            return;
        }
        
        
        if(isalpha(s[idx])){
            str[idx] = toupper(s[idx]);
            helper(idx+1, s, str, result);
            str[idx] = tolower(s[idx]);
            helper(idx+1, s, str, result);
        } else {
            helper(idx+1, s, str, result);
        }
        
    }
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        string str = s;
        helper(0, s, str, result);
        return result;
    }
};