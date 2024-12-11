class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int prind[n];  // previou smaller index
        int nxind[n];  // next smaller index
        stack<int> st;
        // filling previous index
        for(int i=0;i<n;i++){
            while(st.size()>0 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.size()==0) prind[i] = -1;
            else prind[i] = st.top();

            st.push(i);
        }
        // emptying stack
        while(st.size()>0){
            st.pop();
        }
        
        // filling next smaller index
        for(int i=n-1;i>=0;i--){
            while(st.size()>0 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.size()==0) nxind[i] = n;
            else nxind[i] = st.top();

            st.push(i);
        }
        int ans[n];
        for(int i=0;i<n;i++){
            ans[i] = (nxind[i]-prind[i]-1)*heights[i];
        }
        int max = INT_MIN;
        
        for(int i=0;i<n;i++){
            if(max<ans[i]){
                max = ans[i];
            }
        }
        return max;
    }
};
