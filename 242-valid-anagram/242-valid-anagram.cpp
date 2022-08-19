
// Approach 03 : Fixed size array

class Solution {
public:
    bool isAnagram(string s, string t) {
    	// Time : O(n)
        // Spce : O(1) 
    	if(s.size()!=t.size()) return false;
        vector<int>seen(26, 0);
        for(int i=0; i<s.size(); i++){
        		seen[s[i]-'a']++;
        		seen[t[i]-'a']--;
        }
        
        for(int i=0; i<26; i++){
        	if(seen[i]!=0) return false;
        }
        return true;
    }
};