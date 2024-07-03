class Solution {
public:

    bool check(int mid,vector<int> weights,int days){
         int n = weights.size();
         int m = mid;
         int count = 1;
         for(int i=0;i<n;i++){
            if(m>=weights[i]){
                m -= weights[i];
            }
            else{
                count++;
                m = mid;
                m -=weights[i];
            }
         }
         if(count>days) return false;
         else return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int sum = 0;
        int max = INT_MIN;
        for(int i=0;i<n;i++){
            sum+=weights[i];
            if(max<weights[i]) max = weights[i]; 
        }
        int low = max;
        int ans  = sum;
        int high = sum;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(check(mid,weights,days)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};
