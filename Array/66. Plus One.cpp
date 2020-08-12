class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int n = (int)digits.size();
        bool done = 0;
        if(digits[n-1]==9){
            
            for(int i=n-1 ; i>=0 ; i--){
                if(digits[i]!=9){
                    digits[i]++;
                    done = 1;
                    break;
                }else {
                    digits[i]=0;
                }
            }
            cout << digits[0] << endl;
            if(done==0){
                digits[0]=1;
                digits.push_back(0);
            } else {
                digits[n-1]=0;
            }
            
        } else {
             digits[n-1]++;
        }
        return digits;
    }
};