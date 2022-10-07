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
public:
    TreeNode* createBinaryTree(vector<vector<int>>& infos) {
        if(infos.size() == 0) return NULL;
        unordered_map<int, TreeNode*> cache;
        unordered_map<TreeNode* , bool> seen;
        vector<TreeNode*> storeAllParents;
        for(auto& info : infos){
            int parent = info[0], child = info[1], isLeft = info[2];
            TreeNode* childNode;
            TreeNode* parentNode;
            if(cache.find(parent) == cache.end()){
                if(cache.find(child) == cache.end()) {
                    childNode = new TreeNode(child);
                    cache[child] = childNode;
                }
                else {
                    childNode = cache[child];
                }
                parentNode = new TreeNode(parent);
                
                if(isLeft == 1) parentNode->left = childNode;
                else parentNode->right = childNode;
                cache[parent] = parentNode;
            } else {
                parentNode = cache[parent];
                
                if(cache.find(child) == cache.end()) {
                    childNode = new TreeNode(child);
                    cache[child] = childNode;
                }
                else {
                    childNode = cache[child];
                }
                
                if(isLeft == 1) parentNode->left = childNode;
                else parentNode->right = childNode;
            }
            storeAllParents.push_back(parentNode);
            seen[childNode] = true;
        }
        for(auto& parent : storeAllParents){
            if(seen.find(parent) == seen.end()) return parent;
        }
        return NULL;
    }
};