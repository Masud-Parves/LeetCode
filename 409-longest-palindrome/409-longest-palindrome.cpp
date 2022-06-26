class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        if(n<=1) return n;
        
        unordered_map<char, int>cnt;
        for(int i=0; i<n; i++){
            cnt[s[i]]++;
        }
        int result = 0;
        for(auto m : cnt){
            result += m.second/2*2;
            if(result%2 == 0 && (m.second&1)){
                result++;
            }
        }
        return result;
    }
};