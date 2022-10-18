class Solution {
public:
    
    
    string countAndSay(int n) {
        
        if(n==1) return "1";

        string ret = countAndSay(n-1);
        
        string ans="";
        for(int i=0; i<ret.size(); i++){
            int counter=1;
            while(i+1<ret.size() and ret[i]==ret[i+1]){
                i++;
                counter++;
            }
            ans+= to_string(counter);
            ans+=ret[i];
        }
        
        return ans;
    }
};