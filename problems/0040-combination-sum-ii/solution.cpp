class Solution {
    void check(vector<vector <int> > &vec,vector<int> ans,vector<int> &candidates,int target,int idx){
        if(target==0){
            vec.push_back(ans);
            return;
        }
        if(target<0) return;
        for(int i = idx ;i<candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) return;
            ans.push_back(candidates[i]);
            check(vec,ans,candidates,target-candidates[i],i+1);
            ans.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector <int> > vec;
        vector<int> ans;
        int idx = 0;
        check(vec,ans,candidates,target,idx);
        return vec;
    }
};
