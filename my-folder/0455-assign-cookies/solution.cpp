class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int children = g.size();
        int cookies = s.size();
        int i = 0;
        int j = 0;
        int count = 0;
        while(i<children && j<cookies){
            if(g[i]<=s[j]) {
                count++;
                i++;
                j++;
            }
            else {
                j++;
            }
        }
        return count;
    }
};
