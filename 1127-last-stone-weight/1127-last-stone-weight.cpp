class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int num : stones){
            pq.push(num);
        }
        while(pq.size()>1){
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if(x==y){
                if(pq.size()==0) return 0;
                else continue;
            }
            else{
                pq.push(y-x);
            }
        }
        return pq.top();
    }
};