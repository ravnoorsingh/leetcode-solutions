class Solution {
public:

    int getMax(vector<int> nums){
        int max = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(max<nums[i]) max = nums[i];
        }
        return max;
    }

    int getSum(vector<int> nums){
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        return sum;
    }

    int requiredSum(vector<int> nums , int k , int mid){
        int total = 0;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            total += nums[i];
            if(total>mid){
                total = nums[i];
                count++;
            }
        }
        return count;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = getMax(nums);
        int high = getSum(nums);
        while(low<=high){
            int mid = low + (high-low)/2;
            int Sub = requiredSum(nums,k,mid);
            if(Sub >= k){
                low  = mid + 1;
            }
            else high = mid - 1;
        }
        return low;
    }
};