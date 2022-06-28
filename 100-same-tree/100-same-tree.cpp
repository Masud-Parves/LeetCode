class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL or p->val != q->val) return false;
        
        stack<pair<TreeNode*, TreeNode*>> stack;
        
        stack.push({p, q});
        
        while(!stack.empty()){
            TreeNode* pNode = stack.top().first;
            TreeNode* qNode = stack.top().second;
            
            stack.pop();
            
            if(pNode->val != qNode->val) {
                return false;
            }
            
            if(pNode->left && qNode->left) {
                stack.push({pNode->left, qNode->left});
            } else if(pNode->left || qNode->left) {
                return false;
            }
            
            if(pNode->right && qNode->right) {
                stack.push({pNode->right, qNode->right});
            } else if(pNode->right || qNode->right) {
                return false;
            }

        }
        return true;
    }
};