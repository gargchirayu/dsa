/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* helper(int start, int end, vector<int> &nums){
        if(start>end) return NULL;
        
        int mid = (start+end)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(start, mid-1, nums);
        root->right = helper(mid+1, end, nums);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        // TreeNode* root = new TreeNode(nums[n/2]);
        // root->left = helper(0, n/2, nums);
        // root->right = helper(n/2+1, n, nums);
        return helper(0, n-1, nums);
    }
};