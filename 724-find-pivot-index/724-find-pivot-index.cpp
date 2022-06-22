class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0, prefixSum = 0;
        
        for(auto& num : nums){
            totalSum += num;
        }
        for(int i=0; i<n ; i++){
            if(prefixSum == totalSum-prefixSum-nums[i]) return i;
            prefixSum += nums[i];
        }
        return -1;
    }
};