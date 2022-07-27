class Solution {
private:
    bool helper(int idx, int sum, vector<int>& sticks, vector<int>& parts){
        if(idx == sticks.size()){
            return ((parts[0] == parts[1]) && (parts[2] == parts[3]) && (parts[1] == parts[2]));
        }
        
        for(int i=0; i<4; i++){
            if(parts[i]+sticks[idx]<=sum){
                parts[i] += sticks[idx];
                if(helper(idx+1, sum, sticks, parts)) return true;
                parts[i] -=sticks[idx];
            }
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int total = 0;
        
        for(auto& stick : matchsticks){
            total += stick;
        }
        
        if(total%4 != 0){
            return false;
        }
        
        int sum = total/4;
        vector<int> parts(4, 0);
        sort(matchsticks.begin(), matchsticks.end());
        reverse(matchsticks.begin(), matchsticks.end());
        return helper(0, sum , matchsticks, parts);
    }
};