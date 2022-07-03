class Solution {
private:
    void dfsTraversal(TreeNode* node, int depth, unsigned long long levelIndex,unsigned long long& width, map<int, unsigned long long>& table){
        if(node == NULL) return;
        
        if(table.find(depth) == table.end()){
            table[depth] = levelIndex;
        }
        
        width = max(width, levelIndex-table[depth]+1);
        
        dfsTraversal(node->left, depth+1, levelIndex*2, width, table);
        dfsTraversal(node->right, depth+1, levelIndex*2 + 1, width, table);
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long width = 0;
        map<int, unsigned long long> table; // level, firstIdx for each level
        dfsTraversal(root, 0, 0, width, table); // root node, depth aka level, indexing value
        return width;
    }
};