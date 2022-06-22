class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        
        
        vector<int>suffixSum(n);
        vector<int>prefixSum(n);
        
        suffixSum[n-1] = nums[n-1];
        prefixSum[0] = nums[0];
        
        for(int i=1; i<n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
            suffixSum[n-i-1] = suffixSum[n-i] + nums[n-i-1];
        }
        
        for(int i=0; i<n ; i++){
            if(i==0 && i+1<n){
                if(suffixSum[i+1] == 0) return i;
            } else if(i == n-1 && i-1>=0) {
                if(prefixSum[i-1] == 0) return i;
            }
            if(prefixSum[i] == suffixSum[i]){
                return i;
            }
        }
        return -1;
    }
};