class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int count = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='0'){
                    continue;
                }
                count++;
                grid[i][j] = '0';
                queue<pair<int,int> > qu;
                qu.push({i,j});
                while(not qu.empty()){
                    auto curr = qu.front();
                    qu.pop();
                    int currRow = curr.first;
                    int currCol = curr.second;
                    // checking up
                    if(currRow - 1 >=0 && grid[currRow-1][currCol]=='1'){
                        qu.push({currRow-1,currCol});
                        grid[currRow-1][currCol] = '0';
                    }
                    // checking down
                    if(currRow + 1  < rows && grid[currRow+1][currCol]=='1'){
                        qu.push({currRow+1,currCol});
                        grid[currRow+1][currCol] = '0';
                    }
                    // checking left
                    if(currCol - 1 >=0 && grid[currRow][currCol-1]=='1'){
                        qu.push({currRow,currCol-1});
                        grid[currRow][currCol-1] = '0';
                    }
                    // checking right
                    if(currCol + 1 < cols && grid[currRow][currCol+1]=='1'){
                        qu.push({currRow,currCol+1});
                        grid[currRow][currCol+1] = '0';
                    }

                }

            }
        }
        return count;
    }
};
