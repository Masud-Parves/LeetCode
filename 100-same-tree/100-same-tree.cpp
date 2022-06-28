class Solution {
public:
    
    bool check(TreeNode* p, TreeNode* q){
        if(p==NULL && q==NULL) return true;
        //cout << p->val << " " << q->val << endl;
        if(p == NULL or q == NULL or p->val != q->val) return false;
        return true;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL or p->val != q->val) return false;
        
        
        queue < TreeNode* > P, Q;
        P.push(p);
        Q.push(q);
        
        while(!P.empty() && !Q.empty()){
            TreeNode* up = P.front();
            P.pop();
            TreeNode* uq = Q.front();
            Q.pop();
            if(!check(up, uq)) return false;
            if(up != NULL){

                if(!check(up->left, uq->left)) return false;
                //cout << up->left << " left " << uq->left << endl;
                if(!check(up->right, uq->right)) return false;
                //cout << up->right << " right " << uq->right << endl;
                if(up->left && uq->left){
                    P.push(up->left);
                    Q.push(uq->left);
                }
                if(up->right && uq->right){
                    P.push(up->right);
                    Q.push(uq->right);
                }
            }
            
        }
        
        return true;
    }
};