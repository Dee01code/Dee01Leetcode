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
    void solve(TreeNode* p, TreeNode* q, bool &ans){
        
        if(!p && !q) return;
        if(!p || !q){
            ans = 0;
            return;
        }
        if(p->val != q->val){
            ans = 0;
            return;
        }
        solve(p->left,q->left,ans);
        solve(p->right,q->right,ans);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans = 1;
        solve(p,q,ans);
        return ans;
    }
};