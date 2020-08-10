class Solution {
public:
    vector<int> countBits(int num) {
        vector < int > res;
        res.push_back(0);
        for(int i=1 ; i<=num; i++){
            int pre = res[i/2];
            if(i&1){
                res.push_back(pre+1);
            }else res.push_back(pre);
        }
        return res;
    }
};