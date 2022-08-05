class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<vector<char>> dp(numRows);
        int i,j, k;
        i=j=k=0;
        bool dir = true;
        while(k<s.size()){
            if(dir){
                dp[i].push_back(s[k]);
                i++; k++;
                if(i==numRows) {
                    dir = false;
                    i = numRows - 2;
                }
            } else {
                dp[i].push_back(s[k]);
                --i; k++;
                if(i==-1){
                    dir = true;
                    i = 1;
                }
            }
        }
        string ans = "";
        for(int i=0; i<numRows; i++){
            for(int j=0; j<dp[i].size(); j++){
                ans += dp[i][j];
            }
        }
        return ans;
    }
};