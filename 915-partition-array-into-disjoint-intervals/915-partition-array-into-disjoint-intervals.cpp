class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();

        vector<int> minRight(n);
        int currMax = nums[0];
        minRight[n-1] = nums[n-1];
        
        for(int i=n-2; i>=0; i--){
            minRight[i] = min(minRight[i+1], nums[i]);
        }
        
        for(int i=1; i<n; i++){
            if(currMax <= minRight[i]){
                return i;
            }
            currMax = max(currMax, nums[i]);
        }
        return -1;
    }
};