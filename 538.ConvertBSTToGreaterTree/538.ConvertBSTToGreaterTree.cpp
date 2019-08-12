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
    TreeNode* convertBST(TreeNode* root) {
        int accumulation = 0;
        midOrder(root, accumulation);
        return root;
    }
    
    void midOrder(TreeNode* root, int& accumulation) {
        if(root == NULL) {
            return;
        }
        midOrder(root->right, accumulation);
        root->val += accumulation;
        accumulation = root->val;
        midOrder(root->left, accumulation);
    }
};