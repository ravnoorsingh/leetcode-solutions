class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
       int row = matrix.size();  // number of rows
       int column= matrix[0].size(); //number of elements in 0th row i.e. number of columns 
       vector<vector<int>> vec(column,vector<int>(row)); // syntax for initialising 2-d vector
       for(int i=0;i<column;i++){
        for(int j=0;j<row;j++){
            vec[i][j]=matrix[j][i];
        }
       }
       return vec;
    }
};
