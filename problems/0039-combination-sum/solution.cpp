class Solution {
    void check(vector<vector <int> > &vec,vector<int> ans,vector<int> &candidates,int idx,int target){
        if(target<0) return;
        if(target==0){
            vec.push_back(ans);
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            ans.push_back(candidates[i]);
            check(vec,ans,candidates,i,target-candidates[i]);
            ans.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector <int> > vec;
        vector<int> ans;
        int idx = 0 ;
        check(vec,ans,candidates,idx,target);
        return vec;
    }
};
