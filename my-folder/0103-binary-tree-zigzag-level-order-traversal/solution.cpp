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

    void TraversalLR(TreeNode* root,vector<int> &key,int curr,int level){
        if(root==NULL) return;
        if(curr==level){
            key.push_back(root->val);
            return;
        }
        TraversalLR(root->left,key,curr+1,level);
        TraversalLR(root->right,key,curr+1,level);
    }
    void TraversalRL(TreeNode* root,vector<int> &key,int curr,int level){
        if(root==NULL) return;
        if(curr==level){
            key.push_back(root->val);
            return;
        }
        TraversalRL(root->right,key,curr+1,level);
        TraversalRL(root->left,key,curr+1,level);
    }

    void LevelOrder(TreeNode* root,vector<vector<int>> &ans){
        int n = Levels(root);
        vector<int> key;
        for(int i=1;i<=n;i++){
            if(i%2==0){
              TraversalRL(root,key,1,i);  
            }
            else{
                TraversalLR(root,key,1,i); 
            }
            ans.push_back(key);
            key.clear();
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        LevelOrder(root,ans);
        return ans;
    }
};
