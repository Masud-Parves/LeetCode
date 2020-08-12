class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = (int)nums.size();
        if(n==0) return 0;
        int len = 1;
        int idx = 0;
        for(int i=0; i<n-1 ; i++){
            if(nums[i]!=nums[i+1]){
                nums[idx]=nums[i];
                len++;
                idx++;
            }
        }
        nums[idx]=nums[n-1];
        return len;
        
    }
};