class Solution {
public:
    vector<pair<int, int> > internal; // for storing the non-border(internal) nodes
    void dfs(vector<vector<int>>& grid, int row, int col, int originalColor, int newColor){
        if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size() || grid[row][col]!=originalColor) return;
        grid[row][col] = -newColor;

        dfs(grid, row, col-1, originalColor, newColor); // going up
        dfs(grid, row, col+1, originalColor, newColor); // going down
        dfs(grid, row+1, col, originalColor, newColor); // going right
        dfs(grid, row-1, col, originalColor, newColor); // going left

        // below code will execute while coming back form the recursion
        // condition for a node to not be a border node
        if(row!=0 && col!=0 && row!=grid.size()-1 && col!=grid[0].size()-1 && grid[row][col-1]==  -newColor && grid[row][col+1] == -newColor && grid[row+1][col] == -newColor && grid[row-1][col]== -newColor){
            internal.push_back({row,col});
        }
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        if(grid[row][col] == color) return grid;
        int originalColor = grid[row][col];
        dfs(grid, row, col, originalColor, color);

        for(auto p : internal){
            int i = p.first;
            int j = p.second;
            cout<<i<<" "<<j<<endl;
            grid[i][j] = originalColor;
        }

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]<0){
                    grid[i][j] *= -1;
                }
            }
        }
        return grid;
    }
};
