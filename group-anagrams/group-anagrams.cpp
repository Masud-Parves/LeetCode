class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> angrams;
        if(strs.size() == 0) {
            return angrams;
        }
        
        unordered_map<string, vector<string>> ret;
        
        for(auto& str : strs){
            string s = str;
            sort(s.begin(), s.end());
            ret[s].push_back(str);
        }
        
        for(auto& m : ret){
            angrams.push_back(m.second);
        }
        
        return angrams;
    }
};