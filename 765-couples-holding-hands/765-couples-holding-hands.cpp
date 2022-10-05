class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int ret = 0;

        unordered_map<int, int> seen;
        for(int i=0; i<n; i++){
            seen[row[i]] = i;
        }
        
        for(int i=0; i<n; i+=2){
            int val = row[i];
            if(val%2==0){
                // odd ======> 3, find 2
                if(val+1 == row[i+1]) continue;
                else {
                    int idx = seen[val+1];
                    
                    seen[row[i+1]] = idx;
                    seen[row[idx]] = i+1;
                    swap(row[i+1], row[idx]);
                   
                    ret++;
                }
            } else {
                if(val-1 == row[i+1]) continue;
                else {
                    int idx = seen[val-1];
                    
                    seen[row[i+1]] = idx;
                    seen[row[idx]] = i+1;
                    swap(row[i+1], row[idx]);

                    ret++;
                }
            }
        }
        return ret;
    }
};