//recursive soln
TreeNode* insertIntoBST(TreeNode* root, int val) {
        //bc
        if(root == NULL) {
            TreeNode* node = new TreeNode(val);
            return node;
        }

        //sc
        if(val < root->val) {
            root->left = insertIntoBST(root->left, val);
        }
        else if (val >= root->val) {
            root->right = insertIntoBST(root->right, val);
        }

        return root;
}


//iterative soln

TreeNode* insertIntoBST(TreeNode* root, int val) {
    // Base condition
    if(root==NULL){
        return new TreeNode(val);
    }

    TreeNode*temp = root;
    while(true){
        if(temp-> val < val){
            if(temp->right){
                temp = temp->right;
            }
            else{
                temp->right = new TreeNode(val);
                break;
            }
        }
        else{
            if(temp->left){
                temp = temp->left;
            }
            else{
                temp->left = new TreeNode(val);
                break;
            }
        }
    }
    return root;

}
