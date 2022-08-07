class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> result(n);
        stack<int> st;
        
        for(int i=n-1; i>=0; i--){
            st.push(nums[i]);
        }
        
        for(int i=n-1; i>=0; i--){
            if(st.empty()){
                result[i] = -1;
            } else if(!st.empty() && st.top()>nums[i]){
                result[i] = st.top();
            } else {
                while(!st.empty() && st.top()<= nums[i]){
                    st.pop();
                }
                
                if(st.empty()){
                    result[i] = -1;
                } else {
                    result[i] = st.top();
                }
            }
            st.push(nums[i]);
        }
        return result;
    }
};