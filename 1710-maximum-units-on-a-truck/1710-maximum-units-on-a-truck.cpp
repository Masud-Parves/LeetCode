bool cmp(vector<int> const& p1, vector<int> const& p2) {
        return p1[1] > p2[1];
}

class Solution {
public:

    int maximumUnits(vector<vector<int>>& boxTypes, int trackSize) {
        if(trackSize == 0 || boxTypes.size() == 0) {
            return 0;
        }
        
        int result = 0;
        
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        
        for(auto& vect:boxTypes){
            int boxCount = min(trackSize, vect[0]);
            result += (boxCount * vect[1]);
            trackSize -= boxCount;
            if(trackSize == 0) break;
        }
        
        return result;
    }
};