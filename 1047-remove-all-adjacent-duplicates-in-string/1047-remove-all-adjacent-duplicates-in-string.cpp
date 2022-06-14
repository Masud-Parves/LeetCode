class Solution {
public:
    string removeDuplicates(string s) {
        int len = s.size();
        string result = "";
        stack<char>st;
        
        for(int i=0; i<len ; i++){
            if(st.empty() || st.top() != s[i]){
                st.push(s[i]);
            } else if(s[i] == st.top()) {
                st.pop();
            }
        }
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};