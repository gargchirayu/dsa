class Solution {
private:
    int MOD = 1e9+7;
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=arr.size();
        vector<long long> dp(n, 1);
        sort(arr.begin(), arr.end());
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[arr[i]] = i;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                // checking for valid left node and search right on its basis
                if(arr[i]%arr[j]==0){
                    int right = arr[i]/arr[j];
                    if(mp.find(right)!=mp.end()){
                        dp[i] = (dp[i]%MOD) + ((dp[j] * dp[mp[right]])%MOD);
                    }
                }
            }
        }
        
        long long ans=0;
        for(long long i:dp){
            ans += i;
        }
        return ans%MOD;
    }
};