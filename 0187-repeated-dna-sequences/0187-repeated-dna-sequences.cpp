class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        unordered_map<string, int> seen;
        for(int i=0; i+9<n; i++){
            string word = s.substr(i, 10);
            seen[word]++;
        }
        vector<string> result;
        for(auto& m : seen){
            if(m.second>1){
                result.push_back(m.first);
            }
        }
        return result;
    }
};