class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int i:arr){
            mp[i]++;
        }
        int n = arr.size();
        vector<int> freq(n+1, 0);
        for(auto it : mp){
            freq[it.second]++;
        }
        int ans = 0;
        int sum = 0;
        int it=n;
        while(sum<n/2){
            ans++;
            while(freq[it] == 0) --it;
            sum += it;
            freq[it]--;
        }
        
        return ans;
    }
};