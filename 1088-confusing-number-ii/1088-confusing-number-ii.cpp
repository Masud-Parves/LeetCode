class Solution {
private:
    vector<int>com{0, 1, 6, 8, 9};
    void dfs(int& confusingNum, long long num, long long revNum, long long factor, int maxVal){
        if(num>maxVal){
            return;
        }
        
        if(num != revNum){
            confusingNum++;
        }
        
        factor = factor*10;
        for(int i=0; i<5 ; i++){
            if(com[i] == 9 || com[i]==6){
                dfs(confusingNum, num*10+com[i], (15-com[i])*factor+revNum, factor, maxVal);
            } else {
                dfs(confusingNum, num*10+com[i], com[i]*factor+revNum, factor, maxVal);
            }
        }
        return;
    }
public:
    int confusingNumberII(int n) {
        int confusingNum = 0;
        for(int i=1; i<5; i++){
            if(com[i] == 9 || com[i] == 6){
                dfs(confusingNum, com[i], 15-com[i], 1, n);
            } else {
                dfs(confusingNum, com[i], com[i], 1, n);
            }
        }
        return confusingNum;
    }
};