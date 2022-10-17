class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char, int> seen;
        for(auto& ch : sentence){
            seen[ch]++;
        }
        
        for(char c ='a'; c<='z'; c++){
            if(seen[c]<=0){
                return false;
            }
        }
        return true;
    }
};