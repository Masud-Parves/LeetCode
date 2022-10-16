class Solution {
public:
    int mod = 1e9+7;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int maxHeights = INT_MIN;
        int maxWeights = INT_MIN;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int prevVal = 0;
        for(int i=0; i<horizontalCuts.size(); i++){
            int diff = horizontalCuts[i] - prevVal;
            prevVal = horizontalCuts[i];
            maxHeights = max(maxHeights, diff);
        }
        maxHeights = max(maxHeights, h - horizontalCuts.back());
        
        prevVal = 0;
        for(int i=0; i<verticalCuts.size(); i++){
            int diff = verticalCuts[i] - prevVal;
            prevVal = verticalCuts[i];
            maxWeights = max(maxWeights, diff);
        }
        maxWeights = max(maxWeights, w - verticalCuts.back());
        return (maxHeights*1LL*maxWeights)%mod;
    }
};