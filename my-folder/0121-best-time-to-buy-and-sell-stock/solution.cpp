class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_pr=0;
        int n=prices.size();
        int min_pr = INT_MAX;
        for(int i=0;i<n;i++){
            min_pr=min(min_pr,prices[i]);
            max_pr=max(max_pr,prices[i]-min_pr);
        }
        return max_pr;
    }
};
