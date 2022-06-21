class Solution {
private:
    unordered_map<string, int> seen;
    int getInvalidParentheses(string& s){
        int len = s.size();
        stack<char> st;
        
        for(int i=0; i<len ; i++){
            if(s[i] != '(' && s[i] != ')') continue;
            if(st.empty() || s[i] == '(') {
                st.push(s[i]);
            } else {
                if(st.size()>0 && st.top() == '(') {
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }
        }
        return st.size();
    }
    
    void getAllPossibleParentheses(string s, int minInvalid, vector<string>& result){
        
        if(seen[s] != 0) {
            return;
        } else seen[s] = 1;
        
        
        if(minInvalid<0) return;
        if(minInvalid == 0) {
            if(getInvalidParentheses(s) == 0)
                result.push_back(s);
            return;
        }
        
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(' || s[i] == ')'){
                string left = s.substr(0, i), right = s.substr(i+1);            
                getAllPossibleParentheses(left+right, minInvalid-1, result);
            }
        }
    }
    
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        int minInvalid = getInvalidParentheses(s);
        getAllPossibleParentheses(s, minInvalid, result);
        return result;
    }
};