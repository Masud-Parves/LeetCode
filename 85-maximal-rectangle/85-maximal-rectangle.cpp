class Solution {
private:
    void leftSmallest(vector<int>& heights, vector<int>& left){
        int n = heights.size();
        left.resize(n);
        stack<int> st;
        for(int i=0; i<n; i++){
            if(st.empty()){
                left[i] = 0;
            } else if(heights[st.top()]<heights[i]){
                left[i] = st.top()+1;
            } else {
                while(!st.empty() && heights[st.top()]>=heights[i]){
                    st.pop();
                }
                if(st.empty()){
                    left[i] = 0;
                } else {
                    left[i] = st.top()+1;
                }
            }
            st.push(i);
        }
        return;
    }
    
    void rightSmallest(vector<int>& heights, vector<int>& right){
        int n = heights.size();
        right.resize(n);
        stack<int>st;
        
        for(int i=n-1; i>=0; i--){
            if(st.empty()){
                right[i] = n-1;
            } else if(heights[st.top()]<heights[i]){
                right[i] = st.top()-1;
            } else {
                while(!st.empty() && heights[st.top()]>=heights[i]){
                    st.pop();
                }
                if(st.empty()){
                    right[i] = n-1;
                } else {
                    right[i] = st.top()-1;
                }
            }
            st.push(i);
        }
        return;
    }
    
    int MAH(vector<int>& heights){
        int n = heights.size();
        vector<int> left, right;
        leftSmallest(heights, left);
        rightSmallest(heights, right);
        int result = 0;
        
        for(int i=0; i<n; i++){
            //if(r <6) continue;
            result = max(result, heights[i]*(right[i]-left[i]+1));
            //cout << left[i] << " " << right[i] << " " << heights[i] << endl;
        }
        
        return result;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n = matrix.size(), m = matrix[0].size();
        
        vector<int> rowVal(m, 0);
        int result = 0;
        for(int r=0; r<n; r++){
            
            for(int c=0; c<m; c++){
                rowVal[c] = matrix[r][c] == '0' ? 0 : rowVal[c]+1;
            }
            //cout << endl;
            
            int ret = MAH(rowVal);
            result = max(result, ret);
        }
        return result;
    }
};