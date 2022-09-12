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
    void generateAllPath(TreeNode* node, string& path, int& result){
        if(node == NULL){
            return;
        }

        path += to_string(node->val);
        if(node->left == NULL && node->right == NULL){
            result += stoi(path, 0, 2);
        }
        generateAllPath(node->left, path, result);
        generateAllPath(node->right, path, result);
        path.pop_back();
        return;
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        int result = 0;
        string path = "";
        generateAllPath(root, path, result);
        return result;
    }
};