class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs[0];
        for(int i=0; i<min(strs[0].size(), strs[1].size()); i++){
            if(strs[0][i] == strs[1][i]) res += strs[0][i];
            else break;
        }
        if(res == "") return res;
        for(int k=2; k<strs.size(); k++){
            string temp = "";
            for(int i=0; i<min(res.size(), strs[k].size()); i++){
                if(res[i] == strs[k][i]) temp += strs[0][i];
                else break;
            }
            res = temp;
            if(res == "") return res;
        }
        return res;
    }
};