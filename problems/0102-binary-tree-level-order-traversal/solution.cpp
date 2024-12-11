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

    int Levels(TreeNode* root){
        if(root==NULL) return 0;
        int l = Levels(root->left);
        int r = Levels(root->right);
        return 1 + max(l,r);
    }

    
    void LevelOrder(TreeNode* root,vector<vector<int>> &ans,int level){
        if(root==NULL) return;
        ans[level].push_back(root->val);
        LevelOrder(root->left,ans,level+1);
        LevelOrder(root->right,ans,level+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int n = Levels(root);
        vector<int> vec;
        for(int i=1;i<=n;i++){
            ans.push_back(vec);
        }
        LevelOrder(root,ans,0);
        return ans;
    }
};
