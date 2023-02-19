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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return{};
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        vector<int> nums;
        vector<vector<int>> ans;
        
        bool zig = 0;
        
        while(!q.empty()){
            
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp == NULL) continue;
            nums.push_back(temp->val);
            
            if(temp -> left) q.push(temp->left);
            if(temp -> right) q.push(temp->right);
            
            if(q.front() == NULL){
                if(zig){
                    reverse(nums.begin(),nums.end());
                }
                zig ^= 1;
                ans.push_back(nums);
                nums.clear();
                q.push(NULL);
            }
            
        }
        return ans;
        
    }
};