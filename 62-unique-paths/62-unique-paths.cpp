/*
    Problems Link : https://leetcode.com/problems/unique-paths/
    TC - O(n*m)
    SC - O(n*m)
*/

class Solution {
public:
    int uniquePaths(int row, int col) {
        vector<int> previous(col, 0);
        
        for(int r=0; r<row ; r++){
            vector<int> current(col, 0);
            for(int c=0; c<col ; c++){
                if(r==0 && c==0) current[c] = 1;
                else {
                    if(r>0)  current[c] += previous[c];
                    if(c>0)  current[c] += current[c-1]; 
                }
            }
            previous = current;
        }
        return previous[col-1];
    }
};