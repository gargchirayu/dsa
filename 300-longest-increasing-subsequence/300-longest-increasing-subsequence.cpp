class Solution {
private:
    int solve(int ind, int prev, vector<int> &nums, vector<vector<int>> &dp){
        //base case
        if (ind == nums.size()) return 0;
        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
        int take = 0;
        if(prev==-1 or nums[ind] > nums[prev]) take = 1 + solve(ind+1, ind, nums, dp);
        int notTake = solve(ind+1, prev, nums, dp);
        
        return dp[ind][prev+1] = max(take, notTake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return solve(0, -1, nums, dp);
    }
};