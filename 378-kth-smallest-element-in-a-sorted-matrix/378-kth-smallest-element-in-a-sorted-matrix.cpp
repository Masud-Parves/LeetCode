class Solution {
public:
    
    
    /*
    
    [[1,5,9],
    [10,11,13],
    [12,13,15]]
    
    */
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row = matrix.size(), col = matrix[0].size();
        priority_queue<int>Q;
        
        for(int r=0; r<row; r++){
            for(int c=0; c<col; c++){
                Q.push(matrix[r][c]);
            }
        }
        
        int rest = row*col-k;
        while(rest>0){
            rest--;
            Q.pop();
        }
        return Q.top();
    }
};