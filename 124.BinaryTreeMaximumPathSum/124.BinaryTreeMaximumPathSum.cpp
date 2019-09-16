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
    int maxPathSum(TreeNode* root) {
        pair<int, int> ret = maxPath(root);
        return max(ret.first, ret.second);
    }

    pair<int, int> maxPath(TreeNode* root) {
        if(root->left == NULL && root->right == NULL) {
            return make_pair(root->val, root->val);
        }
        pair<int, int> lPair = make_pair(-1000000000, -1000000000);
        pair<int, int> rPair = make_pair(-1000000000, -1000000000);
        if(root->left != NULL) {
            lPair = maxPath(root->left);
        }
        if(root->right != NULL) {
            rPair = maxPath(root->right);
        }
        vector<int> lVec(3);
        lVec[0] = lPair.first + root->val;
        lVec[1] = rPair.first + root->val;
        lVec[2] = root->val;
        int l = maxInVec(lVec);
        vector<int> rVec(5);
        rVec[0] = lPair.first;
        rVec[1] = lPair.second;
        rVec[2] = rPair.first;
        rVec[3] = rPair.second;
        rVec[4] = lPair.first + root->val + rPair.first;
        int r = maxInVec(rVec);
        return make_pair(l, r);
    }

    int maxInVec(vector<int>& vec) {
        int max = vec[0];
        for(int i = 0; i < vec.size(); i++) {
            if(vec[i] > max) {
                max = vec[i];
            }
        }
        return max;
    }
};