class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size(),  start = 0;
        unordered_map<int, int> seen;
        int currSum = 0, maxSum = 0;
        
        for(int end = 0; end<n; end++){
            seen[nums[end]]++;
            
            while(seen[nums[end]] > 1){
                currSum -= nums[start];
                seen[nums[start]]--;
                start++;
            }
            currSum += nums[end];
            maxSum = max(currSum, maxSum);
        }
        
        return maxSum;
    }
};