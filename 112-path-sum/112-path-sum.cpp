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
    
    bool solve(TreeNode* root, int &k, int sum){
        if(!root->left && !root->right){
            if(sum == k) return 1;
            return 0;
        }
        
        bool left = 0;
        if(root->left){
            left = solve(root->left, k, sum + root->left->val);
        }
        bool right = 0;
        if(root->right){
            right = solve(root->right, k, sum + root->right->val);
        }
        return (left || right); 
    }   
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        int sum = root->val;
        return solve(root,targetSum,sum);
    }
};