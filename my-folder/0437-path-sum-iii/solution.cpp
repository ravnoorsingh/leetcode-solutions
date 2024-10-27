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

    void helper(TreeNode* root,long long targetSum,int &count){
        if(root==NULL) return;
        if(targetSum==(long long)root->val) count++;
        helper(root->left,targetSum-(long long)root->val,count);
        helper(root->right,targetSum-(long long)root->val,count);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        int count = 0;
        helper(root,(long long)targetSum,count);
        count += (pathSum(root->left,targetSum) + pathSum(root->right,targetSum));
        return count;
    }
};
