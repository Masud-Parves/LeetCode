class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int n = nums1.size(), m = nums2.size();
        if(n==0 || m == 0) return result;
        
        unordered_map<int, bool> seen;
        for(auto& num : nums1){
            seen[num] = true;
        }
        
        for(auto& num : nums2){
            if(seen.find(num) == seen.end() || seen[num] == false) continue;
            result.push_back(num);
            seen[num] = false;
        }
        
        return result;
    }
};