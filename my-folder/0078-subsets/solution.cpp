class Solution {
public:

    void helper(vector<int> nums,vector<int> &ans,vector<vector <int> > &finalAns,int idx){
        if(idx==nums.size()){
            finalAns.push_back(ans);
            return;
        }
        helper(nums,ans,finalAns,idx+1);
        ans.push_back(nums[idx]);
        helper(nums,ans,finalAns,idx+1);
        ans.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
       vector<int> ans;
       vector<vector <int> > finalAns;
       int idx = 0;
       helper(nums,ans,finalAns,idx);
       return finalAns;
    }
};
