class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int window = 0;
        
        unordered_map<char, int> seen;
        int l = 0, r = 0;
        while(r<n){
            seen[s[r]]++;
            if(seen[s[r]] == 1){
                window = max(window, r-l+1);
            } else {
                while(seen[s[r]]>1){
                    seen[s[l]]--;
                    l++;
                }
                if(seen[s[r]]<=1) {
                    window = max(window, r-l+1);
                }
            }
            r++;
            
        }
        return window;
    }
};