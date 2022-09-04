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
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            TreeNode* cur = node.first;
            int x = node.second.first;
            int y = node.second.second;
            mp[x][y].insert(cur->val);
            if(cur->left) q.push({cur->left, {x-1, y+1}});
            if(cur->right) q.push({cur->right, {x+1, y+1}});
        }
        vector<vector<int>> ans;
        for(auto vert : mp){
            vector<int> lev;
            for(auto level : vert.second){
                lev.insert(lev.end(), level.second.begin(), level.second.end());
            }
            ans.push_back(lev);
        }
        return ans;
    }
};