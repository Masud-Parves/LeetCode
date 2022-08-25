class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        stack<string> simplify;
        
        
        for(int i=0; i<n; i++){
            if(path[i] == '/') continue;
            string word = "";
            
            while(i<n && path[i]!='/') {
                word+=path[i];
                ++i;
            }
            if(word == ".") continue;
            else if(word == ".." ) {
                if(!simplify.empty())
                    simplify.pop();
                continue;
            }
            simplify.push(word);
        }
        string result = "";
        while(!simplify.empty()){
            result = '/' + simplify.top() + result;
            simplify.pop();
        }
        return result.size() == 0 ? "/" : result;
    }
};