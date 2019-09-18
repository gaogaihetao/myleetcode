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
    int _path = 0;

    int pathSum(TreeNode* root, int sum) {
        if(root == NULL) {
            return 0;
        }
        _path += isBegin(root, sum);
        pathSum(root->left, sum);
        pathSum(root->right, sum);
        return _path;
    }
    
    int isBegin(TreeNode* root, int sum) {
        if(root == NULL) {
            return 0;
        }
        int num = 0;
        sum -= root->val;
        if(sum == 0) {
            num++;
        }
        num += isBegin(root->left, sum);
        num += isBegin(root->right, sum);
        return num;
    }
};