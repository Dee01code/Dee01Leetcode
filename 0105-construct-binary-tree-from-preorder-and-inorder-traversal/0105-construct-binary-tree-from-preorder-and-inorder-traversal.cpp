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
    
    TreeNode* solve(vector<int>& in, vector<int>& pre, int a, int b, int &c){
        
        if(a>b) return NULL;
        
        int ind = find(in.begin(), in.end(), pre[c]) - in.begin();
        TreeNode* temp = new TreeNode(pre[c++]);
        
        temp -> left = solve(in, pre, a, ind-1, c);
        temp -> right = solve(in,pre, ind+1, b, c);
        return temp;
         
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int a = 0;
        int b = in.size()-1;
        int c = 0;
        return solve(in,pre,a,b,c);
    }
};