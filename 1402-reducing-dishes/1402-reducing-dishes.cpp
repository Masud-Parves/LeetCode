class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> cache(n+1, vector<int>(n+1, 0));
        
        for(int i=n-1; i>=0; i--){
            for(int t=i; t>=0; t--){
                int way1 = cache[i+1][t];
                int way2 = (t+1)*satisfaction[i] + cache[i+1][t+1];
                cache[i][t] = max(way1, way2);
            }
        }

        return cache[0][0];
    }
};