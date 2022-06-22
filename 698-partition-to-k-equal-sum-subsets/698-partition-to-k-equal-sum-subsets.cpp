class Solution {
private:
    bool partitionKSubsets(vector<int>& nums, int idx, int currSum, int target, string& taken, int countSegment, int k, unordered_map<string, bool>& DP){
        
        
        if(DP.find(taken)!=DP.end()) {
            return DP[taken];
        }
        
        if(countSegment == k-1) {
            return true;
        }
        
        if(currSum>target) {
            return false;
        }
        
        if(currSum == target) {
            return DP[taken] = partitionKSubsets(nums,0, 0, target, taken, countSegment+1, k, DP);
        }
        
        for(int i=idx; i<nums.size(); i++){
            if(taken[i] == '0') {
                taken[i] = '1';
                if(partitionKSubsets(nums, i+1, currSum+nums[i], target, taken, countSegment, k, DP) == true){
                    return DP[taken] = true;
                }
                taken[i] = '0';
            }
        }
        return false;    
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int totalSum = 0;
        for(auto& num : nums){
            totalSum += num;
        }

        if(totalSum%k) return false;
        int target = totalSum/k;
        string taken(n, '0');
        sort(nums.begin(), nums.end(), greater<int>());
        unordered_map<string, bool> DP;
        
        return partitionKSubsets(nums,0, 0, target, taken, 0, k, DP);
    }
};