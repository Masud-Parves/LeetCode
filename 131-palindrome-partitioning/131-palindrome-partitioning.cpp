// Topic : Backtrack
// TC : O(n * 2^n), Hence, there could be 2^{N}2 
/*N possible substrings in the worst case. For each substring, it takes \mathcal{O}(N)O(N) time to generate substring and determine if it a palindrome or not. This gives us time complexity as \mathcal{O}(N \cdot 2^{N})O(N⋅2 
N)
 */
// SC : O(n) . where n is no of max partition. 

class Solution {
    void backtrack(int start, string& s, vector<vector<string>>& result, vector<string>& part, vector<vector<bool>>& DP){
        if(start >= s.length()){
           result.push_back(part);
           return;
        } 
        
        for(int end=start; end < s.length(); end++){
            if(s[start] == s[end] && (end-start<=2 || DP[start+1][end-1] == true)){
                DP[start][end] = true;
                part.push_back(s.substr(start, end-start+1));
                backtrack(end+1, s, result, part, DP);
                part.pop_back();
            }
        }
        return;
    }
public:
    vector<vector<string>> partition(string s) {
        
        int len = s.length();
        vector<vector<string>> result;
        vector<string> part;
        vector<vector<bool>> DP(len, vector<bool>(len, false));
        backtrack(0, s, result, part, DP);
        return result;
    }
};