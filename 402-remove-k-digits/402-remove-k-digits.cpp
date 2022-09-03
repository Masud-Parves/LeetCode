class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int n = num.size();
        int deleted = 0;
        string result = "";
        for(int i=0; i<n; i++){
            while(result.size()>0 && num[i]<result.back() && deleted < k){
                result.pop_back();
                deleted++;
            }
            result += num[i];
        }
    
        while(result.size()>0 && deleted<k){
            result.pop_back();
            deleted++;
        }
        int i=0;
        while(i<result.size() && result[i] == '0') i++;
        return result.substr(i, result.size()-i+1) == "" ? "0" : result.substr(i, result.size()-i+1);
    }
};