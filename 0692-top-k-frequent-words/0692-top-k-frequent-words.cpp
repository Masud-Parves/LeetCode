class Solution {
public:
    static bool mycmp(pair<string, int>& a, pair<string, int>& b){
        if(a.second == b.second){
            return a.first<b.first;
        }
        return a.second > b.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> result;
        unordered_map<string, int> seen;
        for(auto& word : words){
            seen[word]++;
        }
        
        vector<pair<string, int>>cache(seen.begin(), seen.end());
        sort(cache.begin(), cache.end(), mycmp);
        int i=0;
        while(k--){
            result.push_back(cache[i].first);
            i++;
        }
        return result;
    }
};