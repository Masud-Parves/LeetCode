class Solution {
public:
    int maxChunksToSorted(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixMax(n);
        vector<int> suffixMin(n);
        
        for(int i=0; i<n; i++){
            prefixMax[i] = (i==0) ? nums[i] : max(prefixMax[i-1], nums[i]);
        }
        
        
        for(int i=n-1; i>=0; i--){
            suffixMin[i] = (i==n-1) ? nums[i] : min(suffixMin[i+1], nums[i]);
        }
        
        int numOfChunks = 0;
        for(int i=0; i<n-1; i++){
            if(prefixMax[i]<=suffixMin[i+1]){
                numOfChunks++;
            }
        }
        return numOfChunks+1;
    }
};