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
    int kthSmallest(TreeNode* root, int k) {
        int v = 0;
        int cnt = 0;

        tree(root, v, k, cnt);

        return v;
    }

    void tree(TreeNode* root, int& v, int k, int& cnt) {
        if (root == NULL)
            return;

        tree(root->left, v, k, cnt);

        cnt++;

        if (cnt == k) {
            v = root->val;
            return;
        }

        tree(root->right, v, k, cnt);
    }
};