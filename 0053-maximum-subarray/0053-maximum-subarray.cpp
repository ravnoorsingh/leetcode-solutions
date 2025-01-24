class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_curr = -10000;
        int ans =  -10000;
        for(int i=0;i<nums.size();i++){
            max_curr = max(max_curr+nums[i],nums[i]);
            ans = max(ans,max_curr);
        }
        return ans;
    }
};