class Solution {
public:
    int longestValidParentheses(string s) {
        if(s=="") return 0;
        stack<pair<char, int>> st;
        for(int i=0; i<s.size(); i++){
            if(!st.empty() and st.top().first == '(' and s[i] == ')') st.pop();
            else st.push({s[i], i});
        }
        int ans = INT_MIN;
        int x = s.size();
        if(st.empty()) return x;
        while(!st.empty()){
            int temp = st.top().second;
            cout<<temp<<" ";
            st.pop();
            ans = max(x - temp - 1, ans);
            x = temp;
            if(st.empty()) ans = max(ans, temp);
        }
        return ans;
    }
};