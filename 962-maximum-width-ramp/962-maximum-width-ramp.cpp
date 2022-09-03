class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        
        stack<int>stk;
        for(int i=0; i<n; i++){
            if(stk.empty() || nums[stk.top()]>nums[i]) stk.push(i);
        }
        
        int maxRamp = 0;
        for(int i=n-1; i>=0; i--){
            while(!stk.empty() && nums[stk.top()]<=nums[i]){
                maxRamp = max(maxRamp, i-stk.top());
                stk.pop();
            }
        }
        return maxRamp;
    }
};