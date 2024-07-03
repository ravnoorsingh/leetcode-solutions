class Solution {
    bool check(int speed,vector<int>& piles,int hours){
        int n = piles.size();
        int count = 0;
        for(int i=0;i<n;i++){
            if(count>hours) return false;
            if(speed>=piles[i]) count++;
            else if(piles[i]%speed==0) {count += piles[i]/speed;} 
            else count += (piles[i]/speed) + 1;
        }
        if(count>hours) return false;
        else return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int max = INT_MIN;
        
        for(int i=0;i<n;i++){
            if(max<piles[i]) max = piles[i];
        }
        int low = 1;
        int high = max;
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(check(mid,piles,h)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};
