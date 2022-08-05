class Solution {
private:
    int helper(int ind, int target, vector<int> &nums, vector<vector<int>> &dp){
        //base case
        if(target == 0) return dp[ind][target] = 1;
        if(ind == nums.size()) return dp[ind][target] = 0;
        if(dp[ind][target] != -1) return dp[ind][target];
        int take = 0;
        for(int i=0; i<nums.size(); i++)
            if(nums[i]<=target) take += helper(0, target-nums[i], nums, dp);
        //int notTake = helper(ind+1, target, nums);
        
        return dp[ind][target] = take;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return helper(0, target, nums, dp);
    }
};