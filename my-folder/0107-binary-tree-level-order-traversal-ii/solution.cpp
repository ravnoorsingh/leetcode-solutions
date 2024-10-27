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
    int Levels(TreeNode* root){
        if(root==NULL) return 0;
        int l = Levels(root->left);
        int r= Levels(root->right);
        return 1 + max(l,r);
    }

    void Traversal(TreeNode* root,vector<int> &vec,int curr,int level){
        if(root==NULL) return;
        if(curr==level){
            vec.push_back(root->val);
            return;
        }
        Traversal(root->left,vec,curr+1,level);
        Traversal(root->right,vec,curr+1,level);
    }

    vector<vector<int>> LevelOrder(TreeNode* root){
        vector<vector<int>> ans;
        vector<int> vec;
        int n = Levels(root);
        for(int i=1;i<=n;i++){
            Traversal(root,vec,1,i);
            ans.push_back(vec);
            vec.clear();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        return LevelOrder(root);
    }
};
