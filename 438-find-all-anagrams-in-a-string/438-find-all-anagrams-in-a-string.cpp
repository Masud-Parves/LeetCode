class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        unordered_map<char, int> seen;
        for(auto& ch : p){
            seen[ch]++;
        }
        vector<int> ans;
        int window = p.size(), unique = seen.size();
        
        int l = 0;
        for(int r = 0; r<n; r++){
            if(seen.find(s[r]) != seen.end()){
                seen[s[r]]--;
                if(seen[s[r]]==0){
                    unique--;
                }
            }
            
            if(r-l+1 == window){
                if(unique == 0) ans.push_back(l);
                
                if(seen.find(s[l]) != seen.end()){
                    seen[s[l]]++;
                    if(seen[s[l]]==1){
                        unique++;
                    }
                }
                l++;
            }
            
        }
        return ans;
    }
};