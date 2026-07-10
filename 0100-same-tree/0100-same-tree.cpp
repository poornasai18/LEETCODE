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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Case 1:
        // If both nodes are NULL,
        // the trees are identical up to this point.
        if (p == nullptr && q == nullptr)
            return true;

        // Case 2:
        // If one node is NULL and the other isn't,
        // the trees are different.
        if (p == nullptr || q == nullptr)
            return false;

        // Case 3:
        // If the values of the current nodes are different,
        // the trees are not the same.
        if (p->val != q->val)
            return false;

        // Recursively compare the left subtrees.
        bool leftSame = isSameTree(p->left, q->left);

        // Recursively compare the right subtrees.
        bool rightSame = isSameTree(p->right, q->right);

        // The trees are the same only if both
        // left and right subtrees are identical.
        return leftSame && rightSame;
    }
};