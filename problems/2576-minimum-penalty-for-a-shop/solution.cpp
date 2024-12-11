class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        int prefix[n+1]; // number of 'N' before kth hour
        int suffix[n+1]; // number of 'Y' including and after kth hour
        prefix[0] = 0;
        for(int i=0;i<n;i++){
            int Ncount = 0;
            if(customers[i]=='N') Ncount++;
            prefix[i+1] = prefix[i] + Ncount; 
        }
        suffix[n] = 0;
        for(int i=n-1;i>=0;i--){
            int Ycount = 0;
            if(customers[i]=='Y') Ycount++;
            suffix[i] = suffix[i+1] + Ycount;
        }
        int penalty[n+1];
        for(int i=0;i<=n;i++){
            penalty[i] = prefix[i] + suffix[i];
        }
        int min = INT_MAX;
        for(int i=0;i<=n;i++){
            if(min>penalty[i]) min=penalty[i];
        }
        int ans;
        for(int i=0;i<=n;i++){
            if(penalty[i]==min) {
                ans = i;
                break;
            }
        }
        return ans;


    }
};
