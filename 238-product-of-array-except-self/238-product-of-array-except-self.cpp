class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixProducts(n, 1);
        vector<int> suffixProducts(n, 1);
        
        for(int i=0; i<n; i++){
            prefixProducts[i] = (i>0) ? prefixProducts[i-1]*nums[i] : nums[i];
        }

        for(int i=n-1; i>=0; i--){
            suffixProducts[i] = (i+1<n) ? suffixProducts[i+1]*nums[i] : nums[i];
        }
        vector<int>result(n);
        for(int i=0; i<n; i++){
            int left = (i>0) ? prefixProducts[i-1] : 1;
            int right = (i+1<n) ? suffixProducts[i+1] : 1;
            result[i] = left*right;
        }
        return result;
    }
};