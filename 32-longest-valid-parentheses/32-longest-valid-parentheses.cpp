class Solution {
public:
    int longestValidParentheses(string s) {
        // if(s=="") return 0;
        // stack<pair<char, int>> st;
        // for(int i=0; i<s.size(); i++){
        //     if(!st.empty() and st.top().first == '(' and s[i] == ')') st.pop();
        //     else st.push({s[i], i});
        // }
        // int ans = INT_MIN;
        // int x = s.size();
        // if(st.empty()) return x;
        // while(!st.empty()){
        //     int temp = st.top().second;
        //     cout<<temp<<" ";
        //     st.pop();
        //     ans = max(x - temp - 1, ans);
        //     x = temp;
        //     if(st.empty()) ans = max(ans, temp);
        // }
        // return ans;
        
        int open = 0, close = 0, ans = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(') open++;
            else close++;
            if(open == close) ans = max(ans, (open+close));
            else if(close > open) open = close = 0;
        }
        open = close = 0;
        for(int i=s.size()-1; i>=0; --i){
            if(s[i] == '(') open++;
            else close++;
            if(open == close) ans = max(ans, (open+close));
            else if(open > close) open = close = 0;
        }
        return ans;
    }
};