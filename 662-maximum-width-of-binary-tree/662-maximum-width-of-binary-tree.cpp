class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int result = 0;
        if(root == NULL) {
            return result;
        }
        
        queue<pair<TreeNode*, long long>> todo;
        todo.push({root, 0});
        
        while(!todo.empty()){
            int size = todo.size();
            long long minIdx = todo.front().second;
            int firstIdx , lastIdx;
            for(int i=0; i<size; i++){
                TreeNode* node = todo.front().first;
                long long currIdx = todo.front().second - minIdx;
                todo.pop();
                
                if(i == 0) firstIdx = currIdx;
                if(i == size-1) lastIdx = currIdx;
                
                if(node->left != NULL) {
                    todo.push({node->left, 2*currIdx+1});
                }
                if(node->right != NULL) {
                    todo.push({node->right, 2*currIdx+2});
                }
            }
            result = max(result , lastIdx - firstIdx + 1);
        }
        return result;
    }
};