/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int index = 0;

    TreeNode* bstPreorder(vector<int>& preorder, int range) {
        if (index == preorder.size() || preorder[index] > range)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[index++]);

        root->left = bstPreorder(preorder, root->val);
        root->right = bstPreorder(preorder, range);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bstPreorder(preorder, INT_MAX);
    }
};