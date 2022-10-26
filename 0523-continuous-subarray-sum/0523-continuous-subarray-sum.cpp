class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> seen{{0,0}};
        int sum = 0;
        for(int r=0; r<n; r++){
            sum += nums[r];
            
            if(!seen.count(sum%k)){
                seen[sum%k] = r+1;
            } else if(seen[sum%k]<r){
                return true;
            }
            
        }
        return false;
    }
};