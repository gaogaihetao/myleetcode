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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder);
    }
    
    TreeNode* build(vector<int>& preorder, vector<int> inorder) {
        if(preorder.empty() || inorder.empty()) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        preorder.erase(preorder.begin());
        int i = 0;
        for(i; i < inorder.size(); i++) {
            if(inorder[i] == root->val) {
                break;
            }
        }
        root->left = build(preorder, vector<int>(inorder.begin(), inorder.begin()+i));
        root->right = build(preorder, vector<int>(inorder.begin()+i+1, inorder.end()));
        return root;
    }
};