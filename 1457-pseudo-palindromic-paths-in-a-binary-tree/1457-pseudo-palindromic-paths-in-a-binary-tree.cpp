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
    void getAllPalindromicPaths(TreeNode* node, unordered_map<int, int>& seen, int& result){
        if(node == NULL) return;
        
        seen[node->val]++;
        if(node->left == NULL && node->right == NULL){
            int oddAllow = 0;
            
            for(auto& freq : seen){
                if(freq.second&1){
                    oddAllow++;
                    if(oddAllow>1){
                        break;
                    }
                }
            }
            if(oddAllow<=1) result+=1;
            seen[node->val]--;
            return;
        }
        
        getAllPalindromicPaths(node->left, seen, result);
        getAllPalindromicPaths(node->right, seen, result);
        
        seen[node->val]--;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int palindromic = 0;
        unordered_map<int, int> seen;
        getAllPalindromicPaths(root, seen, palindromic);
        return palindromic;
    }
};