/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    // to check if the root even exists in the tree or not 
    bool existsInTree(TreeNode* root,TreeNode* a){
        if(root==NULL) return false;
        if(root->val==a->val) return true;
        return (existsInTree(root->left,a) || existsInTree(root->right,a));
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Condition 1: if an one of the p or q is root node then the LCA will be the root node only
        if(root==p || root==q) return root;

        // Condition 2: if p is at the left side of the root node and q on the right of the root node the the LCA will be the   root only 
        else if(existsInTree(root->left,p) && existsInTree(root->right,q)) return root;

        // Condition 3: if q is at the left side of the root node and p on the right of the root node the the LCA will be the   root only 
        else if(existsInTree(root->right,p) && existsInTree(root->left,q)) return root;

        // Condition 4: if both p and q are somewhere in the left-Subtree(left side of the root node) then start searching for LCA in the left-Subtree
        else if(existsInTree(root->left,p) && existsInTree(root->left,q)) return lowestCommonAncestor(root->left,p,q); 

        // Condition 5: if both p and q are somewhere in the right-Subtree(right side of the root node) then start searching for LCA in the right-Subtree
        else  return lowestCommonAncestor(root->right,p,q);
    }
};
