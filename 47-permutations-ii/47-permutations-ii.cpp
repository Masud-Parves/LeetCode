class Solution {
public:
    
    void generateUniquePermutations(int idx, vector<int> nums, vector<vector<int>>& result){
	    if (idx == nums.size()) {	
            result.push_back(nums);
            for(auto a: nums){
                cout << a << " ";
            }
            cout << endl;
            return;
        }	
        for (int i = idx; i < nums.size(); i++) {	
            if (i == idx || nums[i] != nums[idx]) {	
                swap(nums[idx], nums[i]);	
                generateUniquePermutations(idx+1, nums, result);
            }	
        }	

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>result;
        generateUniquePermutations(0, nums, result);
        return result;
    }
};