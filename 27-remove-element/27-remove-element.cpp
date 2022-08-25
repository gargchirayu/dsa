class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) return 0;
        int rear = nums.size()-1;
        while(rear>=0 and nums[rear]==val) --rear;
        for(int i=0; i<rear; i++){
            if(nums[i]==val) {
                swap(nums[i], nums[rear]);
                while(nums[rear]==val) --rear;
            }
        }
        // if(rear == 0) return 0;
        // else
            return rear+1;
    }
};