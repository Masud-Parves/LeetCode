class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = (int)nums.size();
        int need = n/2;
        map < int, int > cnt;
        for(int i=0 ; i<n ; i++){
            cnt[nums[i]]++;
        }
        
        for(auto a:cnt){
            if(a.second>need){
                return a.first;
            }
        }
        return -1;
    }
};