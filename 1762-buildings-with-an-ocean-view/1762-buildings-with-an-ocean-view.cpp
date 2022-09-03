class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {    
        int n = heights.size();
        vector<int> result;
        stack<int> stk;
        
        for(int i=n-1; i>=0; i--){
            if(stk.empty()){
                result.push_back(i);
                stk.push(heights[i]);
            } else {
                if(heights[i]>stk.top()){
                    while(stk.empty() == false && heights[i]>stk.top()){
                        stk.pop();
                    }
                }
                
                if(stk.empty()) result.push_back(i);
                 stk.push(heights[i]);
            }
            
        }
        sort(result.begin(), result.end());
        return result;
    }
};