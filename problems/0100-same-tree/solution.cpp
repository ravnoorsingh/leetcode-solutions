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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // base cases
        if(p==NULL && q==NULL) return true;
        if((p==NULL && q!=NULL) || (q==NULL && p!=NULL)) return false;

        // condition 1
        if(p->val!=q->val) return false;

        // condition 2
        bool leftAns  = isSameTree(p->left,q->left);
        if (leftAns==false) return false; 

        // condition 2
        bool rigthAns = isSameTree(p->right,q->right);
        if (rigthAns==false) return false; 

        // condition 4
        return true;
    }
};
