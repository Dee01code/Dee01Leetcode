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
    
    vector<TreeNode*> solve(vector<int> nodes, int left, int right){
        if(left>right){
            return {NULL};
        }
        
        vector<TreeNode*> ans;
        for(int i = left; i <= right; i++){
            vector<TreeNode*> ltree = solve(nodes,left,i-1);
            vector<TreeNode*> rtree = solve(nodes,i+1,right);
            int mi = nodes[i];
            for(auto i : ltree)
                for(auto j : rtree){
                    TreeNode* mid = new TreeNode(mi);
                    mid -> left = i;
                    mid -> right = j;
                    ans.push_back(mid);
                }
        }
        return ans;
        
    }
    
    vector<TreeNode*> generateTrees(int n) {
        vector<int> nodes;
        for(int i = 1; i <= n; i++) nodes.push_back(i);
        vector<TreeNode*> ans;
        return solve(nodes,0,n-1);
    }
};