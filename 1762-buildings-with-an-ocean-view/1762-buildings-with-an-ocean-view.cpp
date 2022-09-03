class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {    
        int n = heights.size();
        vector<int> result;
        
        for(int i=0; i<n; i++){
            while(result.size()>0 && heights[result.back()]<=heights[i]){
                result.pop_back();
            }
            result.push_back(i);
        }
        
        return result;
    }
};