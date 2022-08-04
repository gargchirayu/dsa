class Solution {
private:
    int solve(int i, int j, int m, int n, vector<vector<int>> &dp){
        //base case
        if (i==m-1 and j==n-1) return dp[i][j] =  1;
        if (i>=m or j>=n) return 0;
        
        if (dp[i][j]!=-1) return dp[i][j];
        
        int down, bottom;
        down = solve(i+1, j, m, n, dp);
        bottom = solve(i, j+1, m, n, dp);
        
        return dp[i][j] = (down+bottom);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));
        solve(0,0,m,n,dp);
        return dp[0][0];
    }
};