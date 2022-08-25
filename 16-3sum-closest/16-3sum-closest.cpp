class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 0;
        int dif = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++){
            int front = i+1;
            int rear = nums.size()-1;
            while(front<rear){
                int cur = nums[i]+nums[front]+nums[rear];
                if(cur == target) return cur;
                else {
                    if(dif > abs(cur-target)){
                        dif = abs(cur-target);
                        ans = cur;
                    }
                }
                if(cur > target) rear--;
                else front++;
            }
        }
        return ans;
    }
};

// -4 -1 1 2                 1