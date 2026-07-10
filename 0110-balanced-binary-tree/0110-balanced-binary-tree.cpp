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

    // This function returns:
    // - Height of the subtree if it is balanced.
    // - -1 if the subtree is not balanced.
    int checkHeight(TreeNode* root) {

        // Base Case:
        // An empty tree has height 0
        // and is considered balanced.
        if (root == nullptr)
            return 0;

        // Find the height of the left subtree.
        int leftHeight = checkHeight(root->left);

        // If the left subtree is not balanced,
        // return -1 immediately.
        if (leftHeight == -1)
            return -1;

        // Find the height of the right subtree.
        int rightHeight = checkHeight(root->right);

        // If the right subtree is not balanced,
        // return -1 immediately.
        if (rightHeight == -1)
            return -1;

        // If the difference between left and right heights
        // is greater than 1, the tree is not balanced.
        if (abs(leftHeight - rightHeight) > 1)
            return -1;

        // Otherwise, return the height of the current subtree.
        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root) {

        // If checkHeight returns -1,
        // the tree is not balanced.
        return checkHeight(root) != -1;
    }
};