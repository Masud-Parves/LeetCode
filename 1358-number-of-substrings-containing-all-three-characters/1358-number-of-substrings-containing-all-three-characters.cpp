class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        
        int l=0,last =n-1, ans = 0;
        unordered_map<char, int> seen;
        for(int r=0; r<n; r++){
            seen[s[r]]++;
            while(seen['a']>0 && seen['b']>0 && seen['c']>0){
                ans += 1 + (last-r);
                seen[s[l]]--;
                l++;
            }
        }
        return ans;
    }
};