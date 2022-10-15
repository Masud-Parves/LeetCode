class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        unordered_map<int, int> cache;

        int numOfPair = 0;
        
        for(auto& t : time){
            int rem = t%60;
            numOfPair += rem == 0 ? cache[0] : cache[60-rem];
            cache[rem]++;
        }
        return numOfPair;
    }
};