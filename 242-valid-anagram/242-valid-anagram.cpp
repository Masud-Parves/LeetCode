// Approach 01 : hash

class Solution {
public:
    bool isAnagram(string s, string t) {
    		// Time : O(n)
        // Spce : O(n)
        // Hint : Two Pass 
    		if(s.size()!=t.size()) return false;
        unordered_map<char, int> cntS, cntT;
        for(int i=0; i<s.size(); i++){
        		cntS[s[i]]++;
            cntT[t[i]]++;
        }
        
        
        for(auto cnt : cntS){
        	if(cnt.second != cntT[cnt.first]) return false;
        }
        return true;
    }
};