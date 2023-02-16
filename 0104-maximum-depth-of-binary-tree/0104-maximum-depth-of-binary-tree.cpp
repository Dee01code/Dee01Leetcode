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
    
    int solve(TreeNode* root){
        
        if(!root) return 0;
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        return max(left,right)+1;
        
    }
    
    int maxDepth(TreeNode* root) {
        // return solve(root);
        
        if(!root) return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int ans = 0;
        while(!q.empty()){
            
            int t = q.size();
            while(t--){
                TreeNode* p1 = q.front();
                q.pop();
                
                if(p1->right){
                    q.push(p1->right);
                }
                
                if(p1->left){
                    q.push(p1->left);
                }
                
            }
            ans += 1;
        }
        
        return ans;
        
        
    }
};