class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int ,vector<int> >> pq;
        for(auto x : points){
            int y = pow(x[0],2) + pow(x[1],2);
            pq.push({y,x});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int> > res;
        while(pq.size()>0){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
