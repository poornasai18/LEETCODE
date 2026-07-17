/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertutil(TreeNode* &root,int v){
        if(root==NULL) return new TreeNode(v);
        if(root->val>v){
            root->left=insertutil(root->left,v);
        }
        else{
            root->right=insertutil(root->right,v);
        }
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        insertutil(root,val);
        return root;
    }
};