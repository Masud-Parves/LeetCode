class Solution {
public:
    int minPartitions(string s) {
        int n = s.size();
        int firstDigit = s[0]-'0';
        int total = firstDigit, maxDigit = 0;
        for(int i=1; i<n; i++){
            int currDigit = s[i]-'0';
            if(firstDigit<currDigit){
                maxDigit = max(currDigit, maxDigit);
            }
        }
        total += maxDigit == 0 ? 0 : (maxDigit - firstDigit);
        return total;
    }
};