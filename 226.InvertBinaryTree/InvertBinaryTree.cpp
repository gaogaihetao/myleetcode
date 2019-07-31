/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        postOrder(root);
        return root;
    }
    
    void postOrder(TreeNode* root) {
        if(root) {
            invertTree(root->left);
            invertTree(root->right);
            TreeNode* ptr = root->left;
            root->left = root->right;
            root->right = ptr;
        }
    }
};