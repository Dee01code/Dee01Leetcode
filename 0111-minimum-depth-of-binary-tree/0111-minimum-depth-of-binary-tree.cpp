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
    
    int sol(TreeNode* node){
        
        if(node == NULL){
            return 0;
        }
        
        int left = sol(node->left);
        int right = sol(node->right);
        int ans = (min(left,right)? min(left,right) : max(left,right))+1;
        return ans;
        
        
    }
    
    int minDepth(TreeNode* root) {
        
        if(!root) return 0;
        return sol(root);  
    
        
    }
};