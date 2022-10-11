class Solution {
public:
    int minFlips(string s) {
        int len = s.size();
        string str = s + s;
        int n = str.size();
        string s1(n, '0'), s2(n, '1');
        
        for(int i=0; i<n; i+=2){
            swap(s1[i], s2[i]);
        }
        
        int makeS1 = 0, makeS2 = 0;
        
        for(int i=0; i<n/2; i++){
            makeS1 += (s1[i]!=str[i]);
            makeS2 += (s2[i]!=str[i]);
        }
        cout << str << endl;
        cout << s1 << endl << s2 << endl;
        cout << makeS1 << " " << makeS2 << endl;
        int l = 0;
        int ans = min(makeS1, makeS2);
        for(int r=s.size(); r<n; r++){
            makeS1 += (str[r] != s1[r]);
            makeS2 += (str[r] != s2[r]);
            //cout << makeS1 << " " << makeS2 << endl;
            makeS1 -= (str[r] != s1[l]);
            makeS2 -= (str[r] != s2[l]);
            l++;
            ans = min(ans, min(makeS1, makeS2));
        }
        
        return ans;
    }
};