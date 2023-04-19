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

    void solve(TreeNode* root, bool l, bool r, int cnt, int &ans){
        
        if((l && !root -> left)||(r && !root->right)){
            ans = max(ans,cnt);
            return;
        }
        
        if(l){
            solve(root->left, !l, !r, cnt+1, ans);
            solve(root->left, l, r, 0, ans);
        }
        
        if(r){
            solve(root->right, !l, !r, cnt+1, ans);
            solve(root->right, l, r, 0, ans);
        } 
        
    }
    
    int longestZigZag(TreeNode* root) {
        int ans = INT_MIN;
        solve(root,0,1,0, ans);
        solve(root,1,0,0, ans);
        return ans;
        
    }
};