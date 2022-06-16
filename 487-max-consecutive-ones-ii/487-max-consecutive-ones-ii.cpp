class Solution {
public:
    // Time : O(n), Space : O(1), Technique : window sliding Technique
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int cntZero = 0, currWindow = 0, result = 0;
        int l = 0, r = 0;
        while(r<n){
            if(nums[r] == 0) {
                cntZero++;
            }
            currWindow++;
            while(cntZero>1) {
                if(nums[l] == 0) cntZero--;
                l++;
                currWindow--;
            }
            result = max(result, currWindow);
            r++;
        }
        return result;
        
    }
};