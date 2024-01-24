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
    
    int solve(TreeNode* root, unordered_set<int> s){
        
        if(!root->left && !root->right){
            auto it = s.find(root->val);
            if(it != s.end()){
                s.erase(it);
            }
            else
                s.insert(root->val);
            
            if(s.empty() || s.size() == 1)
            {
                // cout << root -> val << endl;
                return 1;
            }
            return 0;
        }
        
        auto it = s.find(root->val);
        if(it != s.end()){
            s.erase(it);
        }
        else
            s.insert(root->val);
        
        int left = root->left ? solve(root->left, s) : 0;
        int right = root->right ? solve(root->right, s) : 0;
        
        return left+right;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_set<int> s;
        int ans = solve(root, s);
        return ans;
    }
};