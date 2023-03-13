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
    
    bool solve(TreeNode* symLeft, TreeNode* symRight){
        if(!symLeft && !symRight) return 1;
        if(!symLeft && symRight) return 0;
        if(symLeft && !symRight) return 0;
        
        bool left = solve(symLeft->left, symRight->right);
        bool right = solve(symLeft->right, symRight->left);  
        bool val = symLeft->val == symRight->val;
        
        if(left && right && val) return 1;
        return 0;
        
    }
    
    bool isSymmetric(TreeNode* root) {
        return solve(root->left, root->right);
    }
};