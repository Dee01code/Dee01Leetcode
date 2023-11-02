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
    
    int ans;
    
    pair<int,int> solve(TreeNode* root){
        
        if(!root) return{0,0};
        
        
        auto lsub = solve(root->left);
        auto rsub = solve(root->right);
        
        int sum = lsub.first + rsub.first + root->val;
        int cnt = lsub.second + rsub.second + 1;
        int avg = sum/cnt;
        ans = (root -> val == avg) ? ans+1 : ans;
        
        return {sum,cnt};
        
    }
    
    int averageOfSubtree(TreeNode* root) {
        ans = 0;
        solve(root);
        return ans;
    }
};