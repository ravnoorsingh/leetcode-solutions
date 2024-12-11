class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int n = nums.size();
        // int noOfZeros = 0;
        // int product1 = 1;
        // int product2 = 1;
        // for(int i=0;i<n;i++){
        //     if(nums[i]==0) noOfZeros++;
        //     product1 *= nums[i];
        //     if(nums[i]!=0) product2 *= nums[i];
        // }
        // for(int i=0;i<n;i++){
        //     if(noOfZeros>1) product2 = 0;
        //     if(nums[i]==0) nums[i] = product2;
        //     else nums[i] = product1 / nums[i]; 
        // }
        // return nums;
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = 1;
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]*nums[i-1];
        }
        vector<int> suffix(n);
        suffix[n-1] = 1;
        for(int i = n-2;i>=0;i--){
            suffix[i] = suffix[i+1]*nums[i+1];
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = prefix[i]*suffix[i];
        }
        return ans;
    }
};
