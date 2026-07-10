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
    bool hasPathSum(TreeNode* root, int targetSum) {

        // Base Case:
        // If the tree is empty,
        // there is no root-to-leaf path.
        if (root == nullptr)
            return false;

        // Check if the current node is a leaf node.
        // A leaf node has no left and right children.
        if (root->left == nullptr && root->right == nullptr) {

            // If the remaining targetSum equals the leaf's value,
            // we found a valid path.
            return (targetSum == root->val);
        }

        // Subtract the current node's value from targetSum.
        int remainingSum = targetSum - root->val;

        // Recursively check the left subtree
        // or the right subtree.
        return hasPathSum(root->left, remainingSum) ||
               hasPathSum(root->right, remainingSum);
    }
};