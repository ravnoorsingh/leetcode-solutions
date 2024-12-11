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


    // Resursive solution
    // void helper(TreeNode* root,vector<int> &ans){
    //     if(root==NULL) return;
    //     ans.push_back(root->val);
    //     helper(root->left,ans);
    //     helper(root->right,ans);
    // }

    // Iterative solution

    void Preorder(TreeNode* root,vector<int> &ans){
        stack<TreeNode*> st;
        if(root!=NULL)st.push(root);
        while(st.size()>0){
            TreeNode* temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            if(temp->right!=NULL) st.push(temp->right);
            if(temp->left!=NULL) st.push(temp->left);
        }
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        Preorder(root,ans);
        return ans;
    }
};
