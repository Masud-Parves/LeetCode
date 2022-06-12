class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        int maxEndHere = nums[0], minEndHere = nums[0], maxProduct = nums[0];
        for(int i=1; i<n ; i++){
            int curMax = maxEndHere;
            maxEndHere = max(nums[i], max(maxEndHere*nums[i], minEndHere*nums[i]));
            minEndHere = min(nums[i], min(curMax*nums[i], minEndHere*nums[i]));
            
            if(maxProduct < maxEndHere){
                maxProduct = maxEndHere;
            }
        }
        
        return maxProduct;
    }
};