class Solution {
public:
    int firstUniqChar(string s) {
        // unordered_map<char, int> mp;
        // for(int i=0; i<s.size(); i++){
        //     if(mp.find(s[i])!=mp.end()) mp[s[i]] = -1;
        //     else mp.insert({s[i], i});
        // }
        // int ans=INT_MAX;
        // for(auto it:mp){
        //     if(it.second != -1) ans = min(ans, it.second);
        // }
        // if(ans==INT_MAX) return -1;
        // return ans;
        
        vector<int> dp(26, 1e6);
        for(int i=0; i<s.size(); i++){
            if(dp[s[i]-97] != 1e6) dp[s[i]-97] = -1;
            else dp[s[i]-97] = i;
        }
        int ans = 1e6;
        for(int i=0; i<26; i++){
            if(dp[i] != -1) ans = min(ans, dp[i]);
        }
        if(ans == 1e6) return -1;
        return ans;
    }
};