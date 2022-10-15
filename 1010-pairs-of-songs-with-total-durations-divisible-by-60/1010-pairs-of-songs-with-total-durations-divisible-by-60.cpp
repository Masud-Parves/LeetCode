class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        unordered_map<int, int> cache;

        int numOfPair = 0;
        
        for(auto& t : time){
            int modulo = t%60;
            numOfPair += modulo == 0 ? cache[0] : cache[60-modulo];
            cache[modulo]++;
        }
        return numOfPair;
    }
};