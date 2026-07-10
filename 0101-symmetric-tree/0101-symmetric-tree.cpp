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

    // Function to check whether two subtrees
    // are mirror images of each other.
    bool isMirror(TreeNode* leftTree, TreeNode* rightTree) {

        // If both nodes are NULL,
        // they are symmetric.
        if (leftTree == nullptr && rightTree == nullptr)
            return true;

        // If only one node is NULL,
        // symmetry is broken.
        if (leftTree == nullptr || rightTree == nullptr)
            return false;

        // If values are different,
        // trees are not symmetric.
        if (leftTree->val != rightTree->val)
            return false;

        // Compare:
        // Left child of left subtree
        // with Right child of right subtree.
        bool outside = isMirror(leftTree->left, rightTree->right);

        // Compare:
        // Right child of left subtree
        // with Left child of right subtree.
        bool inside = isMirror(leftTree->right, rightTree->left);

        // Both comparisons must be true.
        return outside && inside;
    }

    bool isSymmetric(TreeNode* root) {

        // Empty tree is symmetric.
        if (root == nullptr)
            return true;

        // Check whether left and right subtrees
        // are mirror images.
        return isMirror(root->left, root->right);
    }
};