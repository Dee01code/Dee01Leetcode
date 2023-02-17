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
    
    
    void solve(TreeNode* root, vector<int> &ans){
        if(!root) return;
        
        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
    }
    
    int minDiffInBST(TreeNode* root) {
        
        vector<int> ans;
        solve(root,ans);
        int res = INT_MAX;
        for(int i=1; i<ans.size(); i++){
            res = min(abs(ans[i]-ans[i-1]) , res);
        }
        return res;
    }
};