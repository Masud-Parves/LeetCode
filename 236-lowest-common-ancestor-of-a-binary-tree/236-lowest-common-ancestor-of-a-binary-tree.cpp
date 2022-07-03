/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool getPath(TreeNode* node, TreeNode* destNode, vector<int>& path){
        if(node == NULL){
            return false;
        }
        
        path.push_back(node->val);
        
        if(node->val == destNode->val){
            return true;
        }
        
        if(getPath(node->left, destNode, path) || getPath(node->right, destNode, path)) {
            return true;
        }
        
        path.pop_back();
        return false;
    }
    
    TreeNode* getLCA(vector<int>& pathA, vector<int>& pathB){
        int n = pathA.size();
        int m = pathB.size();
        TreeNode* lca = new TreeNode(-1);
        for(int i=0; i<n && i<m; i++){
            if(pathA[i] == pathB[i]){
                lca->val = pathA[i];
            } else break;
        }
        return lca;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int>pathA;
        vector<int>pathB;
        
        getPath(root, p, pathA);
        getPath(root, q, pathB);
        for(auto x: pathA) cout << x <<" "; cout << endl;
        for(auto x: pathB) cout << x << " ";
        TreeNode* lca = getLCA(pathA, pathB);
        
        return lca;
    }
};