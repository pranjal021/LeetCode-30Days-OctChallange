class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        TreeNode* n = new TreeNode(val);
        if(root==NULL)return n;
        
        TreeNode* x = root;
        TreeNode* y = NULL;
        while(x!=NULL){
            y = x;
            if(val < x->val){
                x = x->left;
            }else{
                x = x->right;
            }
        }  
        
        if(val < y->val){
            y->left = n;
        }else{
            y->right = n;
        }
        return root;
        
    }
};