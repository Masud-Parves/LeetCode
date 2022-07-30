class Solution {
private:
    unsigned long long to_integer(string& s){
        unsigned long long val = 0;
        int i=0;
        while(i < s.size()){
            val = val*10 + s[i]-'0';
            i++;
        }
        return val;
    }
    
    bool backtrack(int idx, string& s, unsigned long long prevVal){
        if(idx == s.size()){
            return true;
        }
        
        for(int i=idx; i<s.size(); i++){
            string str = s.substr(idx, i-idx+1);
            unsigned long long currVal = to_integer(str);
            if(prevVal-1 == currVal && backtrack(i+1, s, currVal)) return true;
        }
        return false;
    }
    
public:
    bool splitString(string s) {
        int n = s.size();
        for(int i=0; i<n-1; i++){
            string str = s.substr(0, i+1);
            unsigned long long val = to_integer(str);
            bool back = backtrack(i+1, s, val);
            if(back) return true;
        }
        return false;
    }
};