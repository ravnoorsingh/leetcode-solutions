class Solution {
public:
    int mySqrt(int num) {
        long long low = 0;
        long long high = num;
        int ans;
        while(low<=high){
        long long mid = low + (high-low)/2;
        if((mid*mid)==num || ((mid*mid)<num && ((mid+1)*(mid+1)>num))){
            ans=mid;
            break;
        }
        if((mid*mid)<num){
            low = mid +1;
        }
        if((mid*mid)>num){
            high =  mid - 1;
        }
    }
    return ans;
    }
};
