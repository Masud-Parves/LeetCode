class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int rows = wall.size();
        unordered_map<long long, int> cache;
        int maxEmpty = 0;
        for(int r=0; r<rows ; r++){
            int prev = 0;
            for(int c=0; c<wall[r].size()-1; c++){
                int currVal = prev + wall[r][c];
                cache[currVal]++;
                maxEmpty = max(maxEmpty, cache[currVal]);
                prev = currVal;
            }
        }
        
        return rows-maxEmpty;
    }
};