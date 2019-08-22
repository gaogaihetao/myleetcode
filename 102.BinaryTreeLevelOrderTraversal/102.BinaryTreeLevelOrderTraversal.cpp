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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vv;
        if(root == NULL) {
            return vv;
        }
        queue<pair<TreeNode*, int>> que;
        que.push(make_pair(root, 0));
        int lastLevel = 0;
        vector<int> levelVec;
        while(!que.empty()) {
            TreeNode* node = que.front().first;
            int level = que.front().second;
            que.pop();
            if(level == lastLevel) {
                levelVec.push_back(node->val);
            } else {
                vv.push_back(levelVec);
                levelVec.assign(1, node->val);
                lastLevel = level;
            }
            if(node->left != NULL) {
                que.push(make_pair(node->left, level+1));
            }
            if(node->right != NULL) {
                que.push(make_pair(node->right, level+1));
            }
        }
        vv.push_back(levelVec);
        return vv;
    }
};