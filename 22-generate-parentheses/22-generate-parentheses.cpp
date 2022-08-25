class Solution {
private:
    void helper(int ind, int opctr, int clctr, string &cur, vector<string> &ans, int &n){
        if(ind == 2*n) {
            ans.push_back(cur);
            return;
        }
        if(opctr != n){
            cur.push_back('(');
            helper(ind+1, opctr+1, clctr, cur, ans, n);
            cur.pop_back();
        }
        if(clctr < opctr){
            cur.push_back(')');
            helper(ind+1, opctr, clctr+1, cur, ans, n);
            cur.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur = "";
        helper(0, 0, 0, cur, ans, n);
        return ans;
    }
};