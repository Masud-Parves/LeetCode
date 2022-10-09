class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<int>nextRow(n+1, 0), currentRow(n+1, 0);
        
        for(int i=n-1; i>=0; i--){
            for(int t=i; t>=0; t--){
                int way1 = nextRow[t];
                int way2 = (t+1)*satisfaction[i] + nextRow[t+1];
                currentRow[t] = max(way1, way2);
            }
            nextRow = currentRow;
        }

        return nextRow[0];
    }
};