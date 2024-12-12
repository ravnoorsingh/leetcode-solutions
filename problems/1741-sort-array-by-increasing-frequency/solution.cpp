class Comparator{
    public:
        bool operator()(pair<int,int>&a, pair<int,int>&b){
            if(a.first==b.first){
                return a.second < b.second;
            }
            else return a.first > b.first;
        }
};

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int num : nums){
            freq[num]++;
        }
        priority_queue< pair<int,int> ,vector<pair<int,int>> , Comparator> pq;
        for(auto x : freq){
            pq.push({x.second,x.first});
        }
        vector<int> res;
        while(pq.size()>0){
            auto x = pq.top();
            for(int i=0;i<x.first;i++){
                res.push_back(x.second);
            }
            pq.pop();
        }
        //reverse(res.begin(),res.end());
        return res;
    }
};
