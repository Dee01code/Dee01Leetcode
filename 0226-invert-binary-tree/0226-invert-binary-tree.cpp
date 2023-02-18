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
    
    void solve(TreeNode* root){
        if(!root) return;
        
        if(root->left != NULL && root->right != NULL){
            swap(root->left,root->right);
            // TreeNode* temp = root->left;
            // root->left = root->right;
            // root->right = temp;
            solve(root->left);
            solve(root->right);
        }
        
        else if(root->right ){
            root -> left = root->right;
            root->right = NULL;
            solve(root->left);
        }
        
        else if(root->left){
            root -> right = root->left;
            root->left = NULL;
            solve(root->right);
        }
        
    }
    
    TreeNode* invertTree(TreeNode* root) {
        
        solve(root);
        return root;
        
    }
};