class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> answer(2);
        int len1 = nums1.size(), len2 = nums2.size();
        
        if(len2 == 0){
            return {nums1, answer[1]};
        }
        if(len1 == 0){
            return {answer[0], nums2};
        }
        
        
        
        unordered_map<int, int>seen1, seen2;
        
        for(auto& val : nums1){
            seen1[val]++;
        }
        
        for(auto& val : nums2){
            seen2[val]++;
        }
        
        for(auto& val : nums1){
            if(seen2.find(val) == seen2.end()){
                answer[0].push_back(val);
                seen2[val]++;
            }
        }
        
         for(auto& val : nums2){
            if(seen1.find(val) == seen1.end()){
                answer[1].push_back(val);
                seen1[val]++;
            }
        }
        return answer;
    }
};