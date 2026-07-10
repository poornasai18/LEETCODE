/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int minDepth(TreeNode* root) {

        // Base Case:
        // If the tree is empty,
        // its minimum depth is 0.
        if (root == nullptr)
            return 0;

        // If there is no left child,
        // the minimum depth must come from the right subtree.
        if (root->left == nullptr)
            return 1 + minDepth(root->right);

        // If there is no right child,
        // the minimum depth must come from the left subtree.
        if (root->right == nullptr)
            return 1 + minDepth(root->left);

        // If both children exist,
        // take the smaller depth of the two subtrees.
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};