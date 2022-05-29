class Solution {
private:
    bool check(string& word1, string& word2){
        if(word1.size() != word2.size()-1) return false;
        int small = 0;
        int big = 0;
        while(big<word2.size()){
            if(word1[small] == word2[big]){
                small++;
                big++;
            } else if(word1[small] != word2[big]){
                big++;
            }
            
        }
        if(small == word1.size() && big == word2.size()) return true;
        return false;
    }

public:
    static bool cmp(const string& s1, const string& s2){
        return s1.length() < s2.length();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), cmp);
        int result = 1;
        vector<int> DP(n, 1);
        for(int idx = 0; idx<n ; idx++){
            for(int prev = 0; prev<idx ; prev++){
                if(check(words[prev], words[idx]) && (DP[idx] < DP[prev]+1)){
                    DP[idx] = DP[prev]+1;
                }
                result = max(result, DP[idx]);
            }
        }
        
        return result;
    }
};