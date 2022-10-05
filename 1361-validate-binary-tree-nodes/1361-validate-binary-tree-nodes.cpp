class Solution {
private:
    bool dfs(int node, vector<int>& leftChild, vector<int>& rightChild, vector<bool>& visited, int& count){

        if(visited[node] == true){
            return false;
        }
        visited[node] = true;
        bool left = true, right = true;
        count++;
        if(leftChild[node] != -1){
            left = dfs(leftChild[node], leftChild, rightChild, visited, count);
        }
        if(rightChild[node] != -1){
            right = dfs(rightChild[node], leftChild, rightChild, visited, count);
        }
        return left && right;
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parent(n, -1);
        
        for(int i=0; i<n; i++){
            if(leftChild[i]!=-1){
                parent[leftChild[i]] = i;
            }
            if(rightChild[i]!=-1){
                parent[rightChild[i]] = i;
            }
        }
        
        vector<bool> visited(n, false);
        int count = 0;
        for(int i=0; i<n; i++){
            if(parent[i] == -1){
                bool isCycle = dfs(i, leftChild, rightChild, visited, count);
                return isCycle && count == n;
            }
        }
        return false;
    }
};