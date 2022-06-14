class Solution {
private:
    string mergedLCP(string& left, string& right){
        int minLen = min(left.size(), right.size());
        
        for(int i=0; i<minLen; i++){
            if(left[i] != right[i]){
                return left.substr(0, i);
            }
        }
        return left.substr(0, minLen);
    }
    string getLongestCommonPrefix(vector<string>& strs, int l, int r){
        if( l == r){
            return strs[l];
        }
        int mid = (l+r)/2;
        string leftLCP = getLongestCommonPrefix(strs, l, mid);
        string rightLCP = getLongestCommonPrefix(strs, mid+1, r);
        return mergedLCP(leftLCP, rightLCP);
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0 || strs[0].size() == 0) return "";
        return getLongestCommonPrefix(strs, 0, strs.size()-1);
    }
};