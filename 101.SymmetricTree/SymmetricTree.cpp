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
    bool isSymmetric(TreeNode* root) {
        vector<pair<int, int>> vec;
        midOrder(root, 0, vec);
        for(int i=0; i<vec.size(); i++) {
            if(vec[i].first != vec[vec.size()-i-1].first)
                return false;
            if((vec[i].second+vec[vec.size()-i-1].second) != 0)
                return false;
        }       
        return true;
    }
    
    void midOrder(TreeNode* root, int flag, vector<pair<int, int>>& vec) {
        if(root) {
            midOrder(root->left, -1, vec);
            vec.push_back(pair<int, int>(root->val, flag));
            midOrder(root->right, 1, vec);
        }
    }
};