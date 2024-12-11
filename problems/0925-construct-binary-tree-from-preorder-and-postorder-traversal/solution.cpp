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

    TreeNode* build(vector<int>& preorder, int preLow, int preHigh ,vector<int>& postorder, int postLow, int postHigh){
        if(preLow>preHigh || postLow>postHigh) return NULL;
        TreeNode* root = new TreeNode(preorder[preLow]);
        if(preLow==preHigh) return root;
        int i = postLow;
        while(i<=postHigh){
            if(postorder[i]==preorder[preLow+1]) break;
            i++;
        }
        int leftCount = i-postLow+1;
        root->left = build(preorder, preLow+1, preLow+leftCount, postorder, postLow, postLow+leftCount-1);
        root->right = build(preorder, preLow+leftCount+1, preHigh, postorder, postLow+leftCount, postHigh-1);
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        return build(preorder,0,n-1,postorder,0,n-1);
    }
};
