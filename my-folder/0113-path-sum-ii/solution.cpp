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

    void Path(TreeNode* root,int targetSum,vector<vector<int>> &ans,vector<int> vec){
        if(root==NULL) return;
        vec.push_back(root->val);
        if(targetSum==root->val && root->left==NULL && root->right==NULL){
            ans.push_back(vec);
        }
        Path(root->left,targetSum-root->val,ans,vec); 
        Path(root->right,targetSum-root->val,ans,vec);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> vec;
        Path(root,targetSum,ans,vec);
        return ans;
    }
};
