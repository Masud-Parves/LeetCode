class Solution {
private:
    int getMaxUnique(string& s){
        unordered_map<char, bool> unique;
        for(auto& ch : s){
            unique[ch] = true;
        }
        return unique.size();
    }
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int result = 0;
        int maxUnique = getMaxUnique(s);
        cout << maxUnique << endl;
        for(int currUnique = 1; currUnique<=maxUnique; currUnique++){
            
            unordered_map<char, int> seen;
            int windowStart = 0, windowEnd = 0, blockUnique = 0, meetK = 0;
            while(windowEnd<n){  
                if(blockUnique<=currUnique){
                    seen[s[windowEnd]]++;
                    if(seen[s[windowEnd]] == 1) blockUnique++;
                    if(seen[s[windowEnd]] == k) meetK++;
                    windowEnd++;
                } else {
                    seen[s[windowStart]]--;
                    if(seen[s[windowStart]] == 0) blockUnique--;
                    if(seen[s[windowStart]] == k-1) meetK--;
                    windowStart++;
                }
                
                if(blockUnique == currUnique && meetK == blockUnique){
                    //cout << windowStart << " " << windowEnd << endl;
                    result = max(result, windowEnd-windowStart);
                }
            }
        }

        return result;
    }
};