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
    
    void solve(TreeNode* root, int maxi, int mini){
        if(!root) return;
        ans = max(ans, abs(root->val - maxi));
        ans = max(ans, abs(root->val - mini));
        maxi = max(root->val, maxi);
        mini = min(root->val, mini);
        cout << "At Node " << root->val << " max = " << ans <<endl;
        solve(root->left, maxi, mini);
        solve(root->right, maxi, mini);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        ans = INT_MIN;
        solve(root, root->val, root->val);
        return ans;
    }
};