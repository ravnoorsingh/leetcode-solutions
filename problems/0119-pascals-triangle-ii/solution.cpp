class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vec = {1};
        if(rowIndex==0) return vec;

        for(int i=1;i<=rowIndex;i++){
            vector<int> temp;
            for(int j=0;j<=i;j++){
                if(j==0 || j==i){
                    temp.push_back(1);
                }
                else{
                    temp.push_back(vec[j]+vec[j-1]);
                }
            }
            vec=temp;
        }
       return vec;
    }
};
