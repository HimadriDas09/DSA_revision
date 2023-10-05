/* APPROACH : identify which node has to be deleted, then it's left and right
substree should be a part of the BST, so construct a sorted array out 
of both of subtrees from that node to be deleted. then create a BST of out
that sorted array and attach it to the tree */

class Solution {
public:

    void createSortedArray(TreeNode* root, vector<int> &arr) {
        // bc
        if(root == NULL) return; // nothing in arr

        if(root->left == NULL && root->right == NULL) {
            arr.push_back(root->val);
            return;
        }

        if(root->left != NULL) {
            // go left
            createSortedArray(root->left, arr);
        }

        // push root in arr
        arr.push_back(root->val);

        if(root->right != NULL) {
            // go right
            createSortedArray(root->right, arr);
        }
    }

    TreeNode* constructBST(int si, int ei, vector<int> &arr) {
        // also consider empty arr
        if(si > ei) return NULL;

        int mid = (si+ei)/2;

        TreeNode* midNode = new TreeNode(arr[mid]);

        midNode->left = constructBST(si, mid-1, arr);
        midNode->right = constructBST(mid+1, ei, arr);
        
        return midNode;
    }

    // start from here
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;

        if(key == root->val) {
            // node found: construct an new tree and return it
            vector<int> arr;
            createSortedArray(root->left, arr);
            createSortedArray(root->right, arr);
            delete root;
            int n = arr.size();
            TreeNode* newST = constructBST(0, n-1, arr);
            return newST;
        }
        if(key < root->val) {
            // search in left
            root->left = deleteNode(root->left, key);
        }
        else {
            // search in right
            root->right = deleteNode(root->right, key);
        }

        return root;
    }
};