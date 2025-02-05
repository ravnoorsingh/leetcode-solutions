class Solution {
public:

    int lower_bound(vector<int> ans, int target){
        int low = 0;
        int high = ans.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(ans[mid]>=target){
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                int low_bound = lower_bound(ans,nums[i]);
                ans[low_bound] = nums[i];
            }
        }
        return ans.size();
    }
};