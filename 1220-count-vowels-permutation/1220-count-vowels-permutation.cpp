class Solution {
private:
    int MOD = 1e9 + 7;
    int solve(int cur, int prev, int ind, int n, vector<vector<int>> &dp){
        //base case
        if(prev == 0 and cur != 1) return 0;
        if(prev == 1){
            if(cur == 1 or cur == 3 or cur == 4) return 0;
        }
        if(prev == 2 and cur == 2) return 0;
        if(prev == 3){
            if(cur == 0 or cur == 1 or cur == 3) return 0;
        }
        if(prev == 4 and cur != 0) return 0;
        if(ind==n-1) return 1;
        
        if(dp[ind][cur]!=-1) return dp[ind][cur];
        int res=0;
        for(int i=0; i<5; i++){
            int temp = solve(i, cur, ind+1, n, dp) % MOD;
            res = (res%MOD) + (temp%MOD);
        }
        return dp[ind][cur] = (res % MOD);
    }
public:
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(n, vector<int> (5,-1));
        int ans=0;
        for(int i=0; i<5; i++){
            int temp = solve(i, -1, 0, n, dp) % MOD;
            ans = (ans%MOD) + (temp%MOD);
        }
        return ans % MOD;
    }
};