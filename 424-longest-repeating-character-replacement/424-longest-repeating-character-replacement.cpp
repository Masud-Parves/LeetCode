class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();    
        vector<int>cnt(26, 0);
    
        int left = 0, right = 0, mostFreq = 0, result = 0;
        while(right<n){
            
            cnt[s[right]-'A']++;
            
            mostFreq = max(mostFreq, cnt[s[right]-'A']);
            right++;
            if(right-left-mostFreq>k){
                cnt[s[left]-'A']--;
                left++;
            }
            
            result = max(result, right-left);
        }
            
        return result;
        
    }
};