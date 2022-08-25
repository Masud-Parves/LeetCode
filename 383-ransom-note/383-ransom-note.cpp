class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> cache;
        
        
        for(auto& ch : magazine){
            cache[ch]++;
        }
        
        for(auto& ch : ransomNote){
            if(cache.find(ch)==cache.end() || cache[ch]==0) return false;
            cache[ch]--;
        }
        return true;
    }
};