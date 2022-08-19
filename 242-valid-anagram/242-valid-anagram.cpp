// Approach 02: frequiency count

class Solution {
public:
    bool isAnagram(string s, string t) {
    	// Time : O(n)
        // Spce : O(n)
        // Hint : One O(n) space 
    	if(s.size()!=t.size()) return false;
        unordered_map<char, int> seen;
        for(int i=0; i<s.size(); i++){
        		seen[s[i]]++;
        		seen[t[i]]--;
        }
        
        for(auto m : seen){
        	if(m.second != 0) return false;
        }
        return true;
    }
};