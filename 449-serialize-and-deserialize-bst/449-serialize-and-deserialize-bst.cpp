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
        getline(s,str,',');
        
        queue<TreeNode*>Q;
        TreeNode* root = new TreeNode(stoi(str));
        
        Q.push(root);
        
        while(!Q.empty()){
            TreeNode* currNode = Q.front();
            Q.pop();
            
            getline(s,str,',');
            if(str == "#"){
                currNode->left = NULL;
            } else {
                TreeNode* leftNode = new TreeNode(stoi(str));
                currNode->left = leftNode;
                Q.push(currNode->left);
            }
            
            getline(s,str,',');
            if(str == "#"){
                currNode->right = NULL;
            } else {
                TreeNode* rightNode = new TreeNode(stoi(str));
                currNode->right = rightNode;
                Q.push(currNode->right);
            }
        }

        return root;
    }
};