
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans(k);
        if(x<arr[0]){
            for(int i=0;i<k;i++){
                ans[i]=arr[i];
            }
            return ans;
        }
        if(x>arr[n-1]){
            int i = n-1;
            int j = k-1;
            while(j>=0){
                ans[j]=arr[i];
                j--;
                i--;
            }
            return ans;
        }
        int low = 0;
        int high = n-1;
        bool flag = false;  // to check if x is presenr in the array or not
        int mid = -1;
        int t = 0;
        // binary search
        while(low<=high){
            mid = low + (high-low)/2;
            if(arr[mid]==x){
                flag = true;
                ans[t]= arr[mid];
                t++;
                break;
            }
            else if(arr[mid]>x) high =(mid - 1) ;
            else low = mid + 1;
        }
        int lb = high; // lower bound
        int ub = low;  //upper bound
        if(flag == true){
            lb = mid - 1;
            ub = mid + 1;
        }
        while(t<k && lb>=0 && ub<=n-1){
            int diff_1 = abs(x- arr[lb]);
            int diff_2 = abs(x-arr[ub]);
            if(diff_1<=diff_2){
                ans[t]=arr[lb];
                //t++;
                lb--;
            }
            else { // diff_1 < diff_2
                ans[t]=arr[ub];
                //t++;
                ub++;
            }
            t++;
        }
        if(lb<0){
            while(t<k){
                ans[t]=arr[ub];
                ub++;
                t++;
            }
        }
        if(ub>n-1){
            while(t<k){
                ans[t]=arr[lb];
                lb--;
                t++;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;

    }
};
