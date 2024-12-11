class Solution {
public:

    void fillSieve(vector<bool> &sieve){
        int n = sieve.size();
        for(int i=2;i<=sqrt(n);i++){
            for(int j=i*i;j<=n;j+=i){
                sieve[j]=0;
            }
        }
    }

    int distinctPrimeFactors(vector<int>& nums) {
        int n = nums.size();
        int mx = -1;
        for(int i=0;i<n;i++){
            mx = max(mx,nums[i]);
        }
        vector<bool> sieve(mx+1,1);
        if(n>0) sieve[0] = 0;
        if(n>1) sieve[1] = 0;
        fillSieve(sieve);
        vector<int> prime;
        for(int i=2;i<=mx;i++){
            if(sieve[i]==1) prime.push_back(i);
        }
        vector<int> taken(prime.size(),0);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<prime.size();j++){
                if(prime[j]>nums[i]) break;
                if(nums[i]%prime[j]==0) taken[j]=1;
            }
        }
        int count = 0;
        for(int i=0;i<taken.size();i++){
            if(taken[i]==1) count++;
        }
        return count;

    }
};
