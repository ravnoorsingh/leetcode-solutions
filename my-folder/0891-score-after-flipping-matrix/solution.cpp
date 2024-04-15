class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // toggling every row that has 0 in the starting
        for(int i=0;i<rows;i++){
            if(grid[i][0]==0){
                for(int j=0;j<cols;j++){
                    if(grid[i][j]==0) grid[i][j]=1;
                    else grid[i][j]=0;     
                }
            }
        }

        for(int j=0;j<cols;j++){
            int noo = 0; // number of ones
            int noz = 0; // number of zeros
            for(int i=0;i<rows;i++){
                if(grid[i][j]==0) noz++;
                else noo++;
            }
            if(noz>noo){
                for(int i=0;i<rows;i++){
                    if(grid[i][j]==0) grid[i][j]=1;
                    else grid[i][j]=0;   
                }
            }
        }

        int sum = 0;
        for(int i=0;i<rows;i++){
            int x=1;
            for(int j=cols-1;j>=0;j--){
                sum+=grid[i][j]*x;
                x*=2;
            }
        }
        return sum;
    }
};
