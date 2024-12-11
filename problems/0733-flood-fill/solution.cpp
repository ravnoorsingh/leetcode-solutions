class Solution {
public:
    // the below function will do DFS from currRow, currCol to it's neighbours containing initialColor 
    void dfs(vector<vector<int> > &image, int currRow, int currCol, int initialColor, int newColor){
        int n = image.size();  // n = number of rows
        int m = image[0].size();  // m = number of columns

        if(currRow < 0 || currCol < 0 || currRow >= n || currCol >= m) return; // avoiding going out of the matrix

        if(image[currRow][currCol] != initialColor) return; // if the cells color is not same as the source's color then no need to chage

        image[currRow][currCol] = newColor; // if none of the above conditions are true then change the cell's color to the newColor

        dfs(image, currRow, currCol-1, initialColor, newColor); // going up // checking the upper neighbour

        dfs(image, currRow, currCol+1, initialColor, newColor); // going down // checking the lower neighbour
    
        dfs(image, currRow+1, currCol, initialColor, newColor); // going right // checking the neighbour to the right

        dfs(image, currRow-1, currCol, initialColor, newColor); // going left  // checking the neighbour to the left

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;  // if asking to change to the coclor of the initial cell then changes required, if we had not done this it would have led to overflow(looping) as the color of the neighbouring cell and initial cell would have always be same thus forming cycles leading to overflow

        dfs(image, sr, sc, image[sr][sc] , color); // image[sr][sc] = initialColor , color = newColor

        return image;
    }
};
