class Solution {
public:
    static bool mycmp(pair<string, int>& a, pair<string, int>& b){
        if(a.second == b.second){
            return a.first<b.first;
        }
        return a.second > b.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> seen;
        for(auto& word : words){
            seen[word]++;
        }
        
        vector<pair<string, int>> mostFreq;
        for(auto& m : seen){
            mostFreq.push_back({m.first, m.second});
        }
        sort(mostFreq.begin(), mostFreq.end(), mycmp);
        vector<string> result;
        int i=0;
        while(k--){
            result.push_back(mostFreq[i++].first);
        }
        return result;
    }
};