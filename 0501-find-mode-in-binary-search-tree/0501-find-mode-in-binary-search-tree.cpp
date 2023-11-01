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
    pair<int,int> nodeCnt;
    int maxi;
    
    void solve(TreeNode* root){
        if(!root) return;
        
        solve(root->left);
        
        if(nodeCnt.first != root->val){
            nodeCnt = {root->val,1};
        }
        else nodeCnt.second++;
        
        if(nodeCnt.second >= maxi){
            if(nodeCnt.second > maxi){
                ans.clear();
                maxi = nodeCnt.second;
            }
            ans.emplace_back(nodeCnt.first);
        }
        
        solve(root->right);
        
    }
    
    vector<int> findMode(TreeNode* root) {
        nodeCnt = {-1,0};
        maxi = INT_MIN;
        solve(root);
        return ans;
        
    }
};