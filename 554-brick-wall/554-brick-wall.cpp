class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int rows = wall.size();
        int sumOfRow = 0;
        for(auto& val : wall[0]){
            sumOfRow += val;
        }
        
        unordered_map<long long, int> cache;

        for(int r=0; r<rows ; r++){
            int prev = 0;
            for(int c=0; c<wall[r].size()-1; c++){
                int currVal = prev + wall[r][c];
                cache[currVal]++;
                prev = currVal;
            }
        }
        int maxEmpty = 0;
        for(auto& m : cache){
            maxEmpty = max(maxEmpty, m.second);
        }
        
        return rows-maxEmpty;
    }
};