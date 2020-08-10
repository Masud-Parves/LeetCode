class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for(auto element : nums){
            ones = (ones^element) & (~twos);
            twos = (twos^element) & (~ones);
        }
        return ones;
        
    }
};