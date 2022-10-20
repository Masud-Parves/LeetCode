class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        unordered_map<string, int> cache;
        
        for(int i=0; i+k-1<n; i++){
            string word = s.substr(i, k);
            cache[word]++;
        }
        
        int total = pow(2, k);
        return total == cache.size();
    }
};