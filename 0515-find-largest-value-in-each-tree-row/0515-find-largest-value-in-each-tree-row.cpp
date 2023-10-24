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
    
    vector<int> ans;
    
    int height(TreeNode* root){
        if(!root) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
    
    void solve(TreeNode* root, int lvl){
        if(!root) return;
        ans[lvl] = max(ans[lvl],root->val);
        solve(root->left, lvl+1);
        solve(root->right, lvl+1);
    }
    
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        
        int levels = height(root);
        ans.resize(levels,INT_MIN);
        solve(root,0);
//         vector<int> ans;
//         queue<TreeNode*> q;
//         q.push(root);
        
//         while(!q.empty()){
            
//             int size = q.size();
//             int maxi = INT_MIN;
            
//             while(size--){
//                 TreeNode* node = q.front();
//                 maxi = max(maxi, node->val);
//                 q.pop();
//                 if(node->left) q.push(node->left);
//                 if(node->right) q.push(node->right);
//             }
            
//             ans.push_back(maxi);
            
//         }
        return ans;
    }
};