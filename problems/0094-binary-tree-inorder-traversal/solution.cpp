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

    // Iterative solution
    // void InOrder(TreeNode* root,vector<int> &ans){
    //     stack<TreeNode*> st;
    //     TreeNode* node = root;
    //     while(st.size()>0 || node!=NULL){
    //         if(node!=NULL){
    //             st.push(node);
    //             node = node->left;
    //         }
    //         else{
    //             node = st.top();
    //             st.pop();
    //             ans.push_back(node->val);
    //             node = node->right;
    //         }
    //     }
    // }

    vector<int> MorrisTraversal(TreeNode* root,vector<int> ans){
        TreeNode* curr = root;
        while(curr!=NULL){
            if(curr->left!=NULL){ // Find The Predecessor
                TreeNode* pred = curr->left;
                while(pred->right!=NULL && pred->right!=curr){
                    pred = pred->right;
                }
                if(pred->right==NULL){ // Link
                    pred->right = curr;
                    curr = curr->left;
                }
                else{ // pred->right == curr : Unlink
                    pred->right = NULL;
                    ans.push_back(curr->val);  // visit
                    curr = curr->right;
                }
            }
            else{ // curr->left == NULL
                ans.push_back(curr->val);  // visit
                curr = curr->right;
            }
        }
        return ans;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        return MorrisTraversal(root,ans);
       
    }
};
