class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    	// Time : O(n)
    	// Space : O(1)
        int n = nums.size();
        vector<int>result(n, 0);
        int product = 1, zero = 0;
        for(auto& num : nums){
        	if(num == 0) zero++;
        	else product *= num;
        }

        if(zero>1) return result;

        for(int i=0; i<n; i++){
        	if(zero == 1 && nums[i]!=0){
        		result[i] = 0;
        	} else if(zero == 1 && nums[i]==0){
        		result[i] = product;
        	} else {
        		result[i] = product/nums[i];
        	}
        }
        return result;
    }
};