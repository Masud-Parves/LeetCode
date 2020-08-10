class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector< vector < int > > ret;
        vector < int > st;
        int n =  (int) nums.size();
        for(int i=0 ; i<(1 << n) ; i++){
            for(int j= 0 ; j<n ; j++){
                if(i & (1<<j))
                    st.push_back(nums[j]);
            }
            ret.push_back(st);
            st.clear();
        }
        return ret;
    }
};