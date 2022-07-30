class Solution {
private:
    bool match(string& word, unordered_map<char, int>& freq){
        unordered_map<char, int> freqNow;
        for(auto& c : word){
            freqNow[c]++;
        }
        
        for(char c = 'a' ; c<='z'; c++){
            if(freq.find(c) != freq.end()){
                if(freqNow.find(c) == freqNow.end() || freqNow[c]<freq[c]) return false;
            }
        }
        
        return true;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<string> result;
        unordered_map<char, int>freq;
        
        for(auto& word : words2){
            vector<int>fk(26, 0);
            for(auto& w : word){
                fk[w-'a']++;
            }
            
            for(char c='a'; c<='z'; c++){
                int id = c-'a';
                if(fk[id]){
                    freq[c] = max(fk[id], freq[c]);
                }
            }
        }
        
        
        for(auto& word : words1){
            if(match(word, freq)){
                result.push_back(word);        
            }
        }
        return result;
    }
};