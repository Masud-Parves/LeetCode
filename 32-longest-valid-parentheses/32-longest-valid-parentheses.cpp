class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> stack;

        for(int i=0; i<n; i++){
            if(s[i] == '('){
                stack.push(i);
            } else if(!stack.empty() && s[stack.top()] == '(' && s[i]==')' ){
                stack.pop();
            } else {
                stack.push(i);
            }
        }
        if(stack.empty()) return n;
        
        int longest = 0, last = n, current = 0;
        while(!stack.empty()){
            current = stack.top();
            stack.pop();

            if(longest<last-current-1){
                longest = last-current-1;;
            }
            last = current;
        }
        longest = max(longest, last);
        return longest;
        
    }
};