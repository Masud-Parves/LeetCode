// Topic : Backtrack
// TC : O(n * 2^n), Hence, there could be 2^{N}2 
/*N possible substrings in the worst case. For each substring, it takes \mathcal{O}(N)O(N) time to generate substring and determine if it a palindrome or not. This gives us time complexity as \mathcal{O}(N \cdot 2^{N})O(N⋅2 
N)
 */
// SC : O(n) . where n is no of max partition. 

class Solution {
    
    bool isPali(string& s, int i, int j){
        if(i==j) return true;
        
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    void backtrack(int idx, string& s, vector<vector<string>>& result, vector<string>& part){
        if(idx >= s.length()){
           result.push_back(part);
           return;
        } 
        
        for(int i=idx; i < s.length(); i++){
            if(isPali(s, idx, i)){
                part.push_back(s.substr(idx, i-idx+1));
                backtrack(i+1, s, result, part);
                part.pop_back();
            }
        }
        return;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> part;
        backtrack(0, s, result, part);
        return result;
    }
};