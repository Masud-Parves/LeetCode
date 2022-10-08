class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        
        for(int i=0; i<n; i++){
            int curr = i, left = i+1, right = n-1;
            while(left<right){
                int sum = nums[curr] + nums[left] + nums[right];
                if(abs(diff)>abs(sum-target)){
                    diff = target - sum;
                }
                if(sum<target) {
                    left++;
                } else right--;
            }
        }
        return target - diff;
    }
};