class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<vector<bool>> visited(26, vector<bool>(26));
        
        unordered_map<char, int> left, right;
        for(auto& c : s) right[c]++;
        
        string pali = "";
        int ret = 0;
        for(int i=0; i<n; i++){
            
            char ch = s[i];
            right[ch]--;
            if(right[ch]==0) right.erase(ch);
            
            for(char c = 'a'; c<='z'; c++){
                if(left.find(c) != left.end() && right.find(c) != right.end()){
                    
                    int midIdx = ch-'a';
                    int leftIdx = c -'a';
                    if(visited[midIdx][leftIdx]== true) continue;
                    visited[midIdx][leftIdx] = true;
                    ret++;
                }
            }
            
            left[ch]++;
        }
        
        
        return ret;
    }
};