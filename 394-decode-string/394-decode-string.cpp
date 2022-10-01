class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        string encoded= "";
        stack<char> stack;
        
        for(int i=0; i<n; i++){
            if(s[i] == ']'){
                string decoded_string = "";
                while(!stack.empty() && stack.top() !='['){
                    decoded_string += stack.top();
                    stack.pop();
                }
                
                // pop opening breaket;
                stack.pop();
                
                int k = 0, base = 1;
                
                while(!stack.empty() && isdigit(stack.top())){
                    k = k + (stack.top()-'0')*base;
                    base *= 10;
                    stack.pop();
                }
                
                while(k){
                    for(int idx=decoded_string.size()-1; idx>=0; idx--){
                        stack.push(decoded_string[idx]);
                    }
                    k--;
                }
            } else {
                stack.push(s[i]);
            }
        }
        
        while(!stack.empty()){
            encoded = stack.top() + encoded;
            stack.pop();
        }
        return encoded;
    }
};