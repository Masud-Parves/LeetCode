class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        int how_many = 0;
        for(int i=1; i<n; i++){
            int prevVal = nums[i-1];
            if(prevVal == nums[i]-1) continue;
            
            int now = nums[i]-prevVal-1;
            //cout << how_many << " " << now << endl;
            if(how_many + now >= k){
                int perfect = k - how_many;
                return nums[i-1]+perfect;
            }
            
            how_many += now;
            
        }
        if(how_many<k){
            return nums.back() + k-how_many;
        }
        return -1;
    }
};