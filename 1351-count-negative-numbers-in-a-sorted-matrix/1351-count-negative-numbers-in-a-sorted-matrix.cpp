class Solution {
private:
    int binary_search(vector<int>& nums){
        
        int negativeCount = 0, lastIdx = nums.size()-1;
        int low = 0, high = nums.size()-1, mid;
        
        while(low<=high){
            mid = low + (high-low)/2;
            
            if(nums[mid]>=0){
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        
        if(low>lastIdx) return 0;
        return lastIdx-high;
    }
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int totalNegativeNumber = 0;
        
        for(int r=0; r<rows; r++){
            int ret = binary_search(grid[r]);
            totalNegativeNumber += ret;
        }
        return totalNegativeNumber;
    }
};