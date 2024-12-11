class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector< vector<int> > vec;
        for(int i=0;i<numRows;i++){
            vector<int> v;
            int num=1;
            for(int j=0;j<=i;j++){
                v.push_back(num);
                num=num*(i-j)/(j+1);
            }
            vec.push_back(v);
        }
        return {vec};
    }
};
