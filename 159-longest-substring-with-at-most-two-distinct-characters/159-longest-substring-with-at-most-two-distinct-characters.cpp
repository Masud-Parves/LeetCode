class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size();
        int window = 0, allow = 2, unique = 0;
        
        unordered_map<char, int> seen;
        int l = 0, r = 0;
        while(r<n){
            seen[s[r]]++;
            if(seen[s[r]] == 1) unique++;
            
            if(unique<=allow){
                window = max(window, r-l+1);
            } else {
                while(unique>allow){
                    seen[s[l]]--;
                    if(seen[s[l]] == 0) unique--;
                    l++;
                }
                if(unique<=allow){
                    window = max(window, r-l+1);
                }
            }
            r++;
        }
        return window;
    }
};