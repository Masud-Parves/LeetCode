class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1;
        
        int leftMax = height[left], rightMax = height[right];
        int tapped_water = 0;
        while(left<right){
            
            leftMax = max(height[left], leftMax);
            rightMax = max(height[right], rightMax);
            
            if(height[left]<height[right]){
                tapped_water += leftMax-height[left];
                left++;
            } else {
                tapped_water += rightMax-height[right];
                right--;
            }
            
            
        }
        return tapped_water;
    }
};