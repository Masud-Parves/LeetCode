class Solution {
private:
    int helper(unordered_map<char, int>& freq){
        int ret = 0;
        for(auto& m : freq){
            if(m.second>0){
                ret++;
                m.second--;
                ret+=helper(freq);
                m.second++;
            }
        }
        return ret;
    }
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> freq;
        for(auto& tile : tiles){
            freq[tile]++;
        }
        return helper(freq);
        
    }
};