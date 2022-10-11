//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    int fx[4] = {-1, 1, 0, 0};
    int fy[4] = {0, 0, -1, 1};
    bool isValid(int r, int c, int rows, int cols){
        return r>=0 && r<rows && c>=0 && c<cols;
    }
public:
    int MinimumEffort(vector<vector<int>>& heights) {
        int minEffort = INT_MAX;
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> todo;
        
        dist[0][0] = 0;
        todo.push({0, {0, 0}});
        
        while(!todo.empty()){
           auto info = todo.top();
           todo.pop();
           int uDistance = info.first;
           int uRow = info.second.first;
           int uCol = info.second.second;
           //cout << "cell new : " << uRow << " " << uCol << endl;
           if(uRow == rows-1 && cols-1 == uCol){
               return uDistance;
           }
           for(int k=0; k<4; k++){
               int vRow = uRow + fx[k];
               int vCol = uCol + fy[k];
               if(isValid(vRow, vCol, rows, cols) == true ){
                   
                   int newEffort = max(abs(heights[uRow][uCol]-abs(heights[vRow][vCol])), uDistance);
                   if(newEffort<dist[vRow][vCol]){
                       dist[vRow][vCol] = newEffort;
                       todo.push({newEffort, {vRow, vCol}});
                   }
               }
           }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends