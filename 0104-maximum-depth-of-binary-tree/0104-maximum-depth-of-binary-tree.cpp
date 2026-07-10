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
    int maxDepth(TreeNode* root) {

        // Base Case:
        // If the current node is NULL,
        // its depth is 0.
        if (root == nullptr)
            return 0;

        // Recursively calculate the depth
        // of the left subtree.
        int leftDepth = maxDepth(root->left);

        // Recursively calculate the depth
        // of the right subtree.
        int rightDepth = maxDepth(root->right);

        // The maximum depth of the current tree
        // is the larger of the two subtree depths,
        // plus 1 for the current node.
        return max(leftDepth, rightDepth) + 1;
    }
};