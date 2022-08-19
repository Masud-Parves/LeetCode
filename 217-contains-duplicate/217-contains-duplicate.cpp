class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    	// Time : O(n)
    	// Space : O(n
        unordered_map<int, int> seen;
        for(int i=0; i<nums.size(); i++){
        	if(seen.find(nums[i]) != seen.end()){
        		return true;
        	}
        	seen[nums[i]] = i;
        }
        return false;
    }
};