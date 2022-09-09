bool comp(vector<int>& a, vector<int>& b){
    return (a[0]<b[0]) || (a[0]==b[0] && a[1]>b[1]);
}

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = properties.size();
        
        sort(properties.begin(), properties.end(), comp);
        
        stack<int> stk;

        for(int i=0; i<n; i++){
            
            while(!stk.empty() && properties[stk.top()][1]<properties[i][1]){
                stk.pop();
            }
            stk.push(i);
            
        }
        return n-stk.size();
        
        
    }
};