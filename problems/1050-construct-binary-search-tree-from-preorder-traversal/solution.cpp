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

        // inorder of a BST is sorted
        // so we can find the inorder by sorting the preorder
        // ans if we have both the preorder and inorder then forming a BT is simple by     construction
        // see leetcode 105
class Solution {
public:

    TreeNode* build(vector<int>& preorder, int preLow, int preHigh ,vector<int>& inorder, int inLow, int inHigh){
        if(preLow > preHigh ) return NULL;
        TreeNode* root = new TreeNode(preorder[preLow]);
        if(preLow==preHigh) return root;
        int i = inLow;
        while(i<=inHigh){
            if(inorder[i]==preorder[preLow]) break;
            i++;
        }
        int leftCount = i-inLow;
        int rightCount = inHigh-i;
        root->left  = build(preorder, preLow+1, preLow+leftCount, inorder, inLow,i-1);
        root->right = build(preorder, preLow+leftCount+1 ,preHigh, inorder, i+1, inHigh);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(),inorder.end());
        int n = preorder.size();
        return build(preorder,0,n-1,inorder,0,n-1);
    }
};