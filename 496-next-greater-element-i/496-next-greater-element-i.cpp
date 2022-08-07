class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> result;
        unordered_map<int, int> greater;
        stack<int> st;
        for(int i=m-1; i>=0; i--){
            if(st.empty()){
                greater[nums2[i]] = -1;
            } else if(st.top()>nums2[i]){
                greater[nums2[i]] = st.top();
            } else {
                while(!st.empty() && st.top()<nums2[i]){
                    st.pop();
                }
                if(st.empty()){
                    greater[nums2[i]] = -1;
                } else {
                    greater[nums2[i]] = st.top();
                }
            }
            
            st.push(nums2[i]);
        }
        
        
        for(auto& num : nums1){
            result.push_back(greater[num]);
        }
        return result;
    }
};