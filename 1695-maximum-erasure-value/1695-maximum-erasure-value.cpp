class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l = 0, i = 0;
        unordered_set<int>seen;
        int sum = 0, maxSum = 0;
        while(i<nums.size()){
            
            while(seen.find(nums[i])!=seen.end()){
                seen.erase(nums[l]);
                sum -= nums[l];
                l++;
            }
            sum += nums[i];
            seen.insert(nums[i]);
            maxSum = max(maxSum, sum);
            i++;
        }
        return maxSum;
    }
};