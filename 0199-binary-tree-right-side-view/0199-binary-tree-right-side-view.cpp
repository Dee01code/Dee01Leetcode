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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> ans;
        if(!root) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        
        while(!q.empty()){
            
            TreeNode* temp = q.front();
            q.pop();
            
            if(!temp) continue;
            
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            
            if(q.front() == NULL){
                ans.push_back(temp->val);
                q.push(NULL);
            }
            
        }
        return ans;
    }
};