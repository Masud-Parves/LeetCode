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
    pair<int, int> getNumberData(int idx, string& s){
        bool isNeg = false;
        if(s[idx] == '-') {
            isNeg = true;
            idx++;
        }
        int val = 0;
        while(idx<s.size() && isdigit(s[idx])) {
            int id = s[idx] - '0';
            val = val * 10 + id;
            idx++;
        }
        pair<int, int> ret;
        if(isNeg){
            ret = {-val, idx};
        } else ret = {val, idx};
        return ret;
    }
    
    pair<TreeNode*, int> buildBT(string& s, int idx){
        if(idx == s.size()){
            return {NULL, idx};
        }
        // val, idx
        pair<int, int> numData = getNumberData(idx, s);
        int val = numData.first;
        int index = numData.second;
        
        TreeNode* root = new TreeNode(val);
        pair<TreeNode*, int> data;
        
        if(index<s.size() && s[index] == '('){
            data = buildBT(s, index+1);
            root->left = data.first;
            index = data.second;
        }
        if(root->left != NULL && index<s.size() && s[index] == '('){
            data = buildBT(s, index+1);
            root->right = data.first;
            index = data.second;
        }
        
        pair<TreeNode*, int> ret;
        if(index<s.size() && s[index] == ')') ret = {root, index+1};
        else ret = {root, index};
        return ret;
    }
public:
    TreeNode* str2tree(string s) {
        int n = s.size();
        if(n == 0){
            return NULL;
        }
        pair<TreeNode*, int> data;
        data = buildBT(s, 0);
        return data.first;
    }
};