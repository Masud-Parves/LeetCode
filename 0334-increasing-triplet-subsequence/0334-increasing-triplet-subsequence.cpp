class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int left = INT_MAX, middle = INT_MAX;
        for(auto& num : nums){
            if(num <= left){
                left = num;
            } else if(num <= middle){
                middle = num;
            } else return true;
        }
        return false;
    }
};