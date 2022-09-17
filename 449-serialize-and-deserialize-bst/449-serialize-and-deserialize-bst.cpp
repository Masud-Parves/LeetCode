/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL){
            return "";
        }
        
        string data = "";
        
        queue<TreeNode*>Q;
        Q.push(root);
        while(!Q.empty()){
            TreeNode* currNode = Q.front();
            Q.pop();
            
            if(currNode != NULL){
                data += to_string(currNode->val) + ',';
                Q.push(currNode->left);
                Q.push(currNode->right);
            } else {
                data += "#,";
            }
        }
        
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == ""){
            return NULL;
        }
        
        stringstream s(data);
        string str;
        
        getline(s, str, ',');
        
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*>Q;
        Q.push(root);
        
        while(!Q.empty()){
            TreeNode* currNode = Q.front();
            Q.pop();
            
            
            getline(s, str, ',');
            if(str == "#"){
                currNode->left = NULL;
            } else {
                currNode->left = new TreeNode(stoi(str));
                Q.push(currNode->left);
            }
            
            getline(s, str, ',');
            if(str == "#"){
                currNode->right == NULL;
            } else {
                currNode->right = new TreeNode(stoi(str));
                Q.push(currNode->right);
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;