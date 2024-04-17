class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n==1) return strs[0];
        sort(strs.begin(),strs.end());
        string first = strs[0];
        string last = strs[n-1];
        int k = min(first.size(),last.size());
        string s ="";
        for(int i=0;i<k;i++){
            if(first[i]!=last[i]){
               return s;
            }
            s+=first[i];
        }
        
        // for(int i=0;i<k;i++){
        //     if(first[i]==last[i]){
        //        s+=first[i];
        //        if(i==k-1) return s;
        //     }
        //     else return s;
        // }
        return s;
    }
};
