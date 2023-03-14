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
    
    void solve(TreeNode* root, vector<int> &ans, int num){
        if(!root->left && !root->right){
            num *= 10;
            num += root->val;
            ans.push_back(num);
            return;
        }
        
        num *= 10;
        num += root->val;
        if(root->left) solve(root->left, ans, num);
        if(root->right) solve(root->right,ans,num); 
        
    }
    
    int sumNumbers(TreeNode* root) {
        vector<int> ans;
        solve(root,ans,0);
        
        int sum = accumulate(ans.begin(),ans.end(),0);
        return sum;
    }
};