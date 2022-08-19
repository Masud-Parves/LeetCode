// Approcach 01: Hashmap, sorting


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        int n = strs.size();
        unordered_map<string, vector<string>> cache;
        for(int i=0; i<n; i++){
        	string s = strs[i];
        	sort(s.begin(), s.end());
        	cache[s].push_back(strs[i]);
        }

        for(auto& m : cache){
        	result.push_back(m.second);
        }
        return result;
    }
};