class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int k = 1;
        int len = INT_MIN;
        int maxLen = INT_MIN;
        int zerosFLipped = 0;
        int i = 0;
        int j = 0;
        while(j<n){
            if(nums[j]==1) j++;
            else{
                if(zerosFLipped<k){
                    zerosFLipped++;
                    j++;
                }
                else{ // zerosFLipped = k
                    len = j - i;
                    maxLen = max(maxLen,len);
                    while(nums[i]==1) i++;

                    i++;
                    j++;
                }
            }
        }
        len = j-i;
        maxLen = max(maxLen,len);
        return maxLen-1;
    }
};
