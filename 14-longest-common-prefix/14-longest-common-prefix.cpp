class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        
        string lcp = "";
        for(int i=0; i<strs[0].size(); i++){
            
            bool allMatch = true;
            for(int k = 1; k<n ; k++){
                if(strs[0][i] != strs[k][i]){
                    allMatch = false;
                    break;
                }
            }
            
            if(allMatch == true) {
                lcp += strs[0][i];
            } else break;
            
        }
        return lcp;
    }
};