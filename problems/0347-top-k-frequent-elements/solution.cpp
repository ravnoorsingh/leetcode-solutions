class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int num : nums){
            freq[num]++;
        }
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int> > >pq;
        for(auto x : freq){
            int val = x.first;
            int fr = x.second;
            pq.push({fr,val});
            if(pq.size()>k) pq.pop();
        }
        vector<int> res;
        while(pq.size()>0){
            pair<int,int> p1 = pq.top();
            res.push_back(p1.second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
