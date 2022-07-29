class Solution {
private:
    bool match(string& word, string& pattern){
        
        unordered_map<char, char> mWordToPattern;
        unordered_map<char, char> mPatternToWord;
        for(int i=0; i<word.size(); i++){
            char w = word[i];
            char p = pattern[i];
            
            if(mWordToPattern.find(w) == mWordToPattern.end()){
                mWordToPattern[w] = p;
            }
            
            if(mPatternToWord.find(p) == mPatternToWord.end()){
                mPatternToWord[p] = w;
            }
            
            if(mPatternToWord[p] != w || mWordToPattern[w] != p){
                return false;
            }
        }
        return true;
        
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;
        for(auto& word : words){
            if(match(word, pattern)){
                result.push_back(word);
            }
        }
        return result;
    }
};