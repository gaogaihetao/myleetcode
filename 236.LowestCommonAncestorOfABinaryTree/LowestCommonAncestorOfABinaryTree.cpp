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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p == q) {
            return p;
        }
        stack<TreeNode*> pPath;
        dfs(root, p, pPath);
        stack<TreeNode*> qPath;
        dfs(root, q, qPath);
        while(1) {
            p = pPath.top();
            pPath.pop();
            q = qPath.top();
            qPath.pop();
            if(p == q) {
                root = p;
                continue;
            }
            return root;
        }
        return NULL;
    }
    
    bool dfs(TreeNode* root, TreeNode* p, stack<TreeNode*>& s) {
        if(root == NULL) {
            return false;
        }
        if(root == p) {
            s.push(root);
            return true;
        }
        if(dfs(root->left, p, s)) {
            s.push(root->left);
            return true;
        }
        if(dfs(root->right, p, s)) {
            s.push(root->right);
            return true;
        }
        return false;
    }
};