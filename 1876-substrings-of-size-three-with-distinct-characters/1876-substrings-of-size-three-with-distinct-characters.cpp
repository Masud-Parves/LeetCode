class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();
        
        unordered_map<char, int> seen;
        int l = 0, unique = 0, result = 0;
        
        for(int r=0; r<n; r++){
            seen[s[r]]++;
            
            l = r-3;
            if(l>=0){
                seen[s[l]]--;
                if(seen[s[l]] == 0){
                    seen.erase(s[l]);
                }
            }
            if(seen.size() == 3){
                result++;
            }
            
        }
        return result;
    }
};