class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> seen;
        
        for(auto& ch : t){
            seen[ch]++;
        }
        
        int unique = seen.size();
        
        int l = 0, windows = INT_MAX;
        string result ="";
        for(int r=0; r<s.size(); r++){
            seen[s[r]]--;
            if(seen[s[r]] == 0) unique--;
            
            if(unique == 0){
                
                while(seen[s[l]]<0) {
                    seen[s[l]]++;
                    l++;
                }
                
                if(r-l+1<windows){
                    windows = r-l+1;
                    result = s.substr(l, r-l+1);
                }
                
                seen[s[l]]++;
                if(seen[s[l]] == 1) unique++;
                l++;
            }
        }
        return result;
    }
};