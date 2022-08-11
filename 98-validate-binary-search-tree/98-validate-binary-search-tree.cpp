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
    bool helper(TreeNode* root, long long low, long long high){
        //base case
        if(root==NULL) return true;
        
        if(root->val<=low or high<=root->val) return false;
        bool l = helper(root->left, low, root->val);
        bool r = helper(root->right, root->val, high);
        
        return (l and r);
    }
public:
    bool isValidBST(TreeNode* root) {
        cout<<INT_MIN<<endl<<INT_MAX;
        return helper(root, INT_MIN*1LL - 1LL, INT_MAX*1LL + 1LL);
    }
};