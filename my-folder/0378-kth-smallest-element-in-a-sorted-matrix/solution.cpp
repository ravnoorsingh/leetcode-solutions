class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int r = matrix.size();
        int c = matrix[0].size();
        priority_queue<int> pq;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                pq.push(matrix[i][j]);
                if(pq.size()>k){
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
};
