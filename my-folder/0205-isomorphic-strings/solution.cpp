class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;
        vector <int> vec (200,100);
        for(int i=0;i<s.length();i++){
            int idx = (int) s[i];
            if(vec[idx]==100) vec[idx]=s[i]-t[i];
            else if(vec[idx]!=s[i]-t[i]) return false;
        }

        // resetting the vector
        for(int i=0;i<200;i++){
            vec[i]=100;
        }
    
        for(int i=0;i<t.length();i++){
            int idx = (int) t[i];
            if(vec[idx]==100) vec[idx]=t[i]-s[i];
            else if(vec[idx]!=t[i]-s[i]) return false;
        }
        return true;
    }
};
