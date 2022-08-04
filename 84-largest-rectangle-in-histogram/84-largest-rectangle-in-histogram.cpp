class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size()==1) return heights[0];
        int n = heights.size();
        vector<int> nse(n, n);
        vector<int> pse(n, 0);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() and heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i] = n;
            } else {
                nse[i] = st.top();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=0; i<n; i++){
            while(!st.empty() and heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                pse[i] = -1;
            } else {
                pse[i] = st.top();
            }
            st.push(i);
        }
        // for(int i=0; i<n; i++){
        //     cout<<nse[i]<<"-"<<pse[i]<<" ";
        // }
        // cout<<endl;
        int ans = 0;
        for(int i=0; i<n; i++){
            int cur = (nse[i]-pse[i]-1)*heights[i];
            ans = max(ans, cur);
        }
        return ans;
    }
};