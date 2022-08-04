class Solution {
private:
    int helper(int idx, map<int, int>& points, vector<int>& DP){
        if(idx<=0){
            return 0;
        }
        int& cache = DP[idx];
        if(cache != -1){
            return cache;
        }
        int way1 = helper(idx-1, points, DP);
        if(points.find(idx) == points.end()) points[idx] = 0;
        
        int way2 = points[idx] + helper(idx-2, points, DP);
        return cache = max(way1, way2);
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> points;
        int maxVal = 0;
        for(auto& num : nums){
            points[num] += num;
            maxVal = max(maxVal, num);
        }
        
        vector<int>DP(maxVal+1, -1);
        return helper(maxVal, points, DP);
        
    }
};