class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int k = minutes;
        vector<int> &arr = customers; // arr = customers
        int n = arr.size(); // size of cusotmers
        int maxLoss = 0;
        int prevLoss = 0;
        for(int i=0;i<k;i++){
            if(grumpy[i]==1){
                prevLoss+=arr[i];
            }
        }
        maxLoss = prevLoss;
        int maxIdx = 0;
        int i = 1;
        int j = k;
        while(j<n){
            int currentLoss = prevLoss;
            if(grumpy[j]==1) currentLoss+=arr[j];
            if(grumpy[i-1]==1) currentLoss-=arr[i-1];
            if(maxLoss<currentLoss){
                maxLoss=currentLoss;
                maxIdx = i;
            }
            prevLoss = currentLoss;
            i++;
            j++;
        }
        for(int i=maxIdx;i<maxIdx+k;i++){
            grumpy[i]=0;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0){
                ans+=arr[i];
            }
        }
        return ans;


    }
};
