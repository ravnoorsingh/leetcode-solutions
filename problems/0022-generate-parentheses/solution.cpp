class Solution {
    void paranthesis(vector<string> &ans,int open,int close,string str,int num){
        if(close>open || open>num) return;
        if(open>=close){
            paranthesis(ans,open+1,close,str+'(',num);
            paranthesis(ans,open,close+1,str+')',num);
        }
        if(open==close && open==num){
            ans.push_back(str);
            return;
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open = 0;
        int close = 0;
        string str;
        paranthesis(ans,open,close,str,n);
        return(ans);
    }
};
