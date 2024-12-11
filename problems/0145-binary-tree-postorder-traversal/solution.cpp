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
    // Recursive solution in Note

    // Resursive solution
    // void helper(TreeNode* root,vector<int> &ans){
    //     if(root==NULL) return;
    //     helper(root->left,ans);
    //     helper(root->right,ans);
    //     ans.push_back(root->val);
    // }

    void PostOrder(TreeNode* root,vector<int> &ans){
        stack<TreeNode*> st;
        if(root!=NULL) st.push(root);
        while(st.size()>0){
            TreeNode* temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            if (temp->left!=NULL) st.push(temp->left);
            if(temp->right!=NULL) st.push(temp->right);
        }
        reverse(ans.begin(),ans.end());
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        PostOrder(root,ans);
        return ans;
    }
};