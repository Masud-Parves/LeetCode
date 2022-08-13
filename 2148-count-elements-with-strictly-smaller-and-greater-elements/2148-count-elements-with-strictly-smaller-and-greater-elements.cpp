class Solution {
public:
    int countElements(vector<int>& nums) {
        int result = 0;
        sort(nums.begin(), nums.end());
        for(auto& currNum : nums){
            if(nums.front()<currNum && currNum<nums.back()) result++;
        }
        return result;
    }
};