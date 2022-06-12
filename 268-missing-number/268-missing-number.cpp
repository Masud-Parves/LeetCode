class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = (n*(n+1))/2, actualSum  = 0;
        
        for(auto num : nums){
            actualSum += num;
        }
        
        return expectedSum - actualSum;
    }
};