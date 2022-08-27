class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> maxLeft(n);
        vector<int> minRight(n);
        
        maxLeft[0] = nums[0];
        minRight[n-1] = nums[n-1];
        for(int i=1; i<n; i++){
            maxLeft[i] = max(maxLeft[i-1], nums[i]);
        }
        
        for(int i=n-2; i>=0; i--){
            minRight[i] = min(minRight[i+1], nums[i]);
        }
        
        for(int i=1; i<n; i++){
            if(maxLeft[i-1] <= minRight[i]){
                return i;
            }
        }
        return -1;
    }
};