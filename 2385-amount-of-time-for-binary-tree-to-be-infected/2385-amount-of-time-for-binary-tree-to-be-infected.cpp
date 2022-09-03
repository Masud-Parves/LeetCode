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
class Solution {
private:
    TreeNode*  bfsToMakeParent(TreeNode* root, int start, unordered_map<TreeNode*, TreeNode*>& parent){
        
        TreeNode* target;
        queue<TreeNode*> Q;
        Q.push(root);
        parent[root] = NULL;
        while(!Q.empty()){
            TreeNode* node = Q.front();
            if(node->val == start){
                target = node;
            }
            Q.pop();
            
            if(node->left != NULL){
                parent[node->left] = node;
                Q.push(node->left);
            }
            
            if(node->right != NULL){
                parent[node->right] = node;
                Q.push(node->right);
            }
        }
        return target;
    }
    
    int bfsLevelOrder(TreeNode* node , unordered_map<TreeNode*, TreeNode*>& parent){
        queue<TreeNode*> Q;
        
        unordered_map<TreeNode*, int> visited;
        Q.push(node);
        visited[node] = 1;
        
        int level = 0;
        while(!Q.empty()){
            int size = Q.size();
            //cout << size << endl;
            for(int i=0; i<size; i++){
                TreeNode* uNode = Q.front();
                Q.pop();
                
                if(uNode->left != NULL && visited.find(uNode->left) == visited.end()){
                    Q.push(uNode->left);
                    visited[uNode->left] = 1;
                }
                if(uNode->right != NULL && visited.find(uNode->right) == visited.end()){
                    Q.push(uNode->right);
                    visited[uNode->right] = 1;
                    
                }
                if(parent[uNode] != NULL && visited.find(parent[uNode]) == visited.end()){
                    Q.push(parent[uNode]);
                    visited[parent[uNode]] = 1;
                }
            }
            level++;
        }

        return level-1;
    }
    
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* target = bfsToMakeParent(root, start, parent);
        int minTime = bfsLevelOrder(target, parent);
        return minTime;
    }
};