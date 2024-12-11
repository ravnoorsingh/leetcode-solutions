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

    TreeNode* InOrderPred(TreeNode* root){
    if(root->left==NULL) return NULL;
    TreeNode* pred = root->left;
    while(pred->right!=NULL){
        pred = pred->right;
    }
    return pred;
}

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
        return NULL;
    }
    if(root->val==key){
        // Case 1: No Child
        if(root->left==NULL && root->right==NULL) return NULL;

        // Case 2: One Child
        if(root->left==NULL || root->right==NULL){
            if(root->left!=NULL) return root->left;
            else return root->right;
        }

        // Case 3: Two Child
        if(root->left!=NULL && root->right!=NULL){
            TreeNode* predecessor = InOrderPred(root);
            root->val = predecessor->val;
            root->left = deleteNode(root->left,predecessor->val);
        }
        
    }
    else if(root->val < key){
        root->right = deleteNode(root->right,key);
    }
    else if(root->val > key){
        root->left = deleteNode(root->left,key);
    }
    return root;
    }
};
