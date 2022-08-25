class Solution {
private: 
    vector<string> map = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void helper(int ind, string &cur, string &digits, vector<string> &ans){
        if(ind==digits.size()) {
            if(cur == "") return;
            ans.push_back(cur);
            return;
        }
        for (int i=0; i<map[digits[ind]-'0'-2].size(); i++){
            cur.push_back(map[digits[ind]-'0'-2][i]);
            helper(ind+1, cur, digits, ans);
            cur.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string cur = "";
        helper(0, cur, digits, ans);
        return ans;
    }
};