class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();  // number of rows
        int column = matrix[0].size();   // number of columns
        int minr=0;
        int maxr=row-1;
        int minc=0;
        int maxc=column-1;
        int tne = row*column;  // total number of elements
        int count=0;
        vector<int> res;
        while(count<tne){
            // minimun row
            for(int j=minc;j<=maxc && count<tne;j++){
                res.push_back(matrix[minr][j]);
                count++;
            }
            minr++;

            // maximun column
            for(int i=minr;i<=maxr && count<tne;i++ ){
                res.push_back(matrix[i][maxc]);
                count++;
            }
            maxc--;

            // maximum row
            for(int j=maxc;j>=minc && count<tne;j--){
                res.push_back(matrix[maxr][j]);
                count++;
            }
            maxr--;

            // minimum column
            for(int i=maxr;i>=minr && count<tne;i--){
                res.push_back(matrix[i][minc]);
                count++;
            }
            minc++;
        }
        return res;

    }
};
