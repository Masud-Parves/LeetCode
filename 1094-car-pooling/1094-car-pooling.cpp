class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> seen;
        for(auto& trip : trips){
            int p = trip[0], s = trip[1], e = trip[2];
            seen[s] += p;
            seen[e] -= p;
        }
        int currPassangers = 0;
        for(auto& m : seen){
            currPassangers += m.second;
            if(currPassangers>capacity){
                return false;
            }
        }
        return true;
    }
};