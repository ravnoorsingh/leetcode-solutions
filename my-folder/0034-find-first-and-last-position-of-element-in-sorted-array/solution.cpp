class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int x) {
        int low = 0;
        int high = arr.size()-1;
        vector<int> ans(2,-1);
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[mid]==x){
                ans[0]=mid;
                high = mid - 1;
            }
            else if(arr[mid]<x){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        low = 0;
        high = arr.size()-1;
        int second = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[mid]==x){
                ans[1] = mid;
                low = mid + 1;
            }
            else if(arr[mid]<x){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        
    return ans;
    }
    
    

                
};
