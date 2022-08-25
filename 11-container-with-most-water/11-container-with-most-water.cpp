class Solution {
public:
    int maxArea(vector<int>& height) {
        int front = 0;
        int rear = height.size()-1;
        int ans = INT_MIN;
        while(front < rear){
            int cur = (rear-front)*min(height[front], height[rear]);
            ans = max(ans, cur);
            if(height[front] < height[rear]) front++;
            else if (height[front] > height[rear]) rear--;
            else {
                if(height[front+1] < height[rear-1]) rear--;
                else front++;
            }
        }
        return ans;
    }
};