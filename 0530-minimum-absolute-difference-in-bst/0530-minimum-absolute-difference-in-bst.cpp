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
    
    
    void inorder(TreeNode* root, vector<int>& seq){
        if(!root) return;
        inorder(root->left,seq);
        seq.push_back(root->val);
        inorder(root->right,seq);
    }
    
    int getMinimumDifference(TreeNode* root) {
        vector<int> seq;
        inorder(root,seq);
        int ans = INT_MAX;
        for(int i = 1; i<seq.size();i++){
            int diff = seq[i]-seq[i-1];
            ans = min(ans,diff);
        }
        return ans;
    }
};