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

    void helper(TreeNode** root){
        if(*root==NULL) return;
        TreeNode* temp = *root;
        TreeNode* a = temp->left;
        temp->left = temp->right;
        temp->right = a;
        helper(&temp->left);
        helper(&temp->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        helper(&root);
        return root;
    }
};
