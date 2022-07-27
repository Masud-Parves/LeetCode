class Solution {
private:
    int min(int a, int b){
        if(a<=b) return a;
        return b;
    }
    
    void backtrack(int idx, int dots, string& s, string combo, vector<string>& result){
        
        if(dots == 4 && idx == s.size()){
            combo.pop_back();
            result.push_back(combo);
            return;
        }
        
        if(dots>4){
            return;
        }
        
        string sub ="";
        for(int i = idx ; i<min(idx+3, s.size()); i++){
            sub += s[i];
            int num = stoi(sub);
            if(num>255 || (sub.size()>1 && sub[0]=='0')) continue;
            backtrack(i+1, dots+1, s, combo+ sub + '.', result);
        }
        return;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        int n = s.size();
        if(n>12){
            return result;
        }

        backtrack(0, 0, s, "", result);
        return result;
    }
};