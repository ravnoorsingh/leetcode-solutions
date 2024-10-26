class Solution {
public:

    // void rightBoundry(TreeNode* root,vector<int> &ans){
    //     if(root==NULL) return;
    //     ans.push_back(root->val);
    //     if(root->right==NULL) rightBoundry(root->left,ans);
    //     rightBoundry(root->right,ans);
    // }

    int Levels(TreeNode* root){
        if(root==NULL) return 0;
        int l = Levels(root->left);
        int r = Levels(root->right);
        return 1 + max(l,r);
    }

    void rightMostElement(TreeNode* root,vector<int> &ans,int index,int curr,int levels){
        if(root==NULL) return;
        if(curr==levels) ans[index] = root->val;
        rightMostElement(root->left,ans,index,curr+1,levels);
        rightMostElement(root->right,ans,index,curr+1,levels);
    }

    vector<int> rightBoundry(TreeNode* root){
        int n = Levels(root);
        vector<int> ans(n);
        for(int i=1;i<=n;i++){
            rightMostElement(root,ans,i-1,1,i);
        }
        return ans;
    }

    vector<int> rightSideView(TreeNode* root) {
       return rightBoundry(root);
    }
};
