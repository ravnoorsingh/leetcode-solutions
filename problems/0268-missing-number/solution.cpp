class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // method 1
        // int n = nums.size();
        // vector<int> vec(n+1,false);
        // for(int i=0;i<n;i++){
        //     int ele = nums[i];
        //     vec[ele] = true;
        // }
        // for(int i=0;i<=n;i++){
        //     if(vec[i]==false) return i;
        // }
        // method 2
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int total = (n*(n+1))/2;
        return (total-sum);
        return 0;
    }
};
