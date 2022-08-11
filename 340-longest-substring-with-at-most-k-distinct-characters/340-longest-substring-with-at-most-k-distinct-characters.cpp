class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int K) {
        int n = s.size();
        int window = 0;
        
        unordered_map<char, int> seen;
        int l = 0, r = 0, unique = 0;
        while(r<n){
            seen[s[r]]++;
            if(seen[s[r]] == 1) unique++;
            
            if(unique <= K) {
                window = max(window, r-l+1);
            } else {
                while(unique>K){
                    seen[s[l]]--;
                    if(seen[s[l]] == 0)
                        unique--;
                    l++;
                }
                if(unique<=K){
                    window = max(window, r-l+1);
                }
            }
            r++;
        }
        return window;
    }
};