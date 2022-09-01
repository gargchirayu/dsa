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
private: void dfs(TreeNode* root, int maxi, int &ctr){
    if(root == NULL) return;
    if(root->val >= maxi) {
        maxi = root->val;
        ctr++;
    }
    dfs(root->left, maxi, ctr);
    dfs(root->right, maxi, ctr);
}
public:
    int goodNodes(TreeNode* root) {
        int ctr = 0;
        int maxi = INT_MIN;
        dfs(root, maxi, ctr);
        return ctr;
    }
};