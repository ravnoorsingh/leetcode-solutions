class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int> > pq;
        for(int num : arr){
            int dist = abs(x-num);
            pq.push({dist,num});
            if(pq.size()>k) pq.pop();
        }
        vector<int> res;
        while(pq.size()>0){
            auto x = pq.top();
            res.push_back(x.second);
            pq.pop();
        }
        sort(res.begin(),res.end());
        return res;
    }
};