/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class CBTInserter {
private:
    queue<TreeNode*> todo;
    TreeNode* newRoot;
public:
    CBTInserter(TreeNode* root) {
        newRoot = root;
        queue<TreeNode*> currQueue;
        currQueue.push(root);

        while(!currQueue.empty()){
            int size = currQueue.size();

            for(int i=0; i<size; i++){
                TreeNode* currNode = currQueue.front();
                currQueue.pop();
                
                if(currNode->left == NULL ){
                    todo.push(currNode);
                } else if(currNode->right == NULL){
                    todo.push(currNode);
                }
                if(currNode->left != NULL){
                    currQueue.push(currNode->left);
                }
                if(currNode->right != NULL){
                    currQueue.push(currNode->right);
                }
            }
        }     
    }
    
    int insert(int val) {
        TreeNode* currNode = todo.front();
        if(currNode->left == NULL){
            currNode->left = new TreeNode(val);
            todo.push(currNode->left);
            return currNode->val;
        }
        if(currNode->right == NULL){
            currNode->right = new TreeNode(val);
            todo.pop();
            todo.push(currNode->right);
            return currNode->val;
        }
        return -1;
    }
    
    TreeNode* get_root() {
        return newRoot;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */