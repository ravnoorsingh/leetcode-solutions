class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // vector<int> a = edges[0];
        // vector<int> b = edges[1];
        // if(a[0]==b[0] || a[0]==b[1]) return a[0];
        // else return a[1];
        int a = edges[0][0];
        int b = edges[0][1];
        
        int c = edges[1][0];
        int d = edges[1][1];

        return ( a==c or a==d) ? a : b;
    }
};
