class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxFruits = 0, allowItems = 2;
        
        unordered_map<int, int> seen;
        int l = 0, r = 0, uniqueItems = 0;
        
        for(int r = 0; r<n; r++){
            seen[fruits[r]]++;
            if(seen[fruits[r]] == 1) uniqueItems++;
            if(uniqueItems<=allowItems){
                maxFruits = max(maxFruits, r-l+1);
            } else {
                while(uniqueItems>allowItems){
                    seen[fruits[l]]--;
                    if(seen[fruits[l]] == 0) uniqueItems--;
                    l++;
                }
                if(uniqueItems <= allowItems){
                    maxFruits = max(maxFruits, r-l+1);
                }
            }
        }
        return maxFruits;
    }
};