class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        unordered_map<int, int> cache;

        int numOfPair = 0;
        for(auto& t : time){
            int modulo = t%60;
            numOfPair += cache[(60-modulo)%60];
            cache[modulo]++;
        }
        return numOfPair;
    }
};