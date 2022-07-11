class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0) {
            return 0;
        }
        
        unordered_map<char, int> seen;
        int result = 1;
        int l = 0;
        for(int r=0; r<n; r++){
            seen[s[r]]++;
            if(seen[s[r]]>1) {
                while(seen[s[r]]!=1){
                    seen[s[l]]--;
                    l++;
                }
            }
            result = max(result , r-l+1);
        }
        return result;
    }
};