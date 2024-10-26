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
    //     helper(root->left,ans);
    //     ans.push_back(root->val);
    //     helper(root->right,ans);
    // }

    void InOrder(TreeNode* root,vector<int> &ans){
        stack<TreeNode*> st;
        TreeNode* node = root;
        while(st.size()>0 || node!=NULL){
            if(node!=NULL){
                st.push(node);
                node = node->left;
            }
            else{
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        InOrder(root,ans);
        return ans;
    }
};
