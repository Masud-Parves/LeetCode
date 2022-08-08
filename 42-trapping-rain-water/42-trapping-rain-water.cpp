class Solution {
public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        vector<int>rightMax(n);
        int maxVal = 0;
        for(int i=n-1; i>=0; i--){
            maxVal = max(maxVal, heights[i]);
            rightMax[i] = maxVal;
        }
        int leftMax = heights[0];
        int result = 0;
        for(int i=1; i<n-1; i++){
            //cout << leftMax << " " << rightMax[i+1] << endl;
            result += max(0, min(leftMax, rightMax[i+1])-heights[i]);
            leftMax = max(leftMax, heights[i]);
        }
        return result;
    }
};