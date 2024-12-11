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

    TreeNode* build(vector<int>& inorder, int inLow, int inHigh,vector<int>& postorder ,int postLow, int postHigh){
        if(postLow>postHigh) return NULL;
        TreeNode* root = new TreeNode(postorder[postHigh]);
        if(postLow==postHigh) return root;
        int i = inLow;
        while(i<=inHigh){
            if(inorder[i]==postorder[postHigh]) break;
            i++;
        }
        int leftCount = i-inLow;
        root->left = build(inorder, inLow, i-1, postorder, postLow, postLow+leftCount-1);
        root->right = build(inorder , i+1, inHigh, postorder, postLow+leftCount, postHigh-1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return build(inorder,0,n-1,postorder,0,n-1);
    }
};
