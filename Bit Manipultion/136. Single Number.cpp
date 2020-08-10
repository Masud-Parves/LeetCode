class Solution {
public:

    int singleNumber(vector<int>& nums) {

        int n = (int)nums.size();
        map < int , int > cnt;
        for(int i=0 ; i<n ; i++){
            cnt[nums[i]]++;
        }

        for(auto a: cnt){
            if(a.second == 1){
                return a.first;
            }
        }
        return -1;
    }
};
