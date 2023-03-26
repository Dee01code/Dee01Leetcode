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
    
    TreeNode* solve(vector<int>& in, vector<int>& po, int a, int b, int &c){
        
        if(a>b) return NULL;
        
        int ind = find(in.begin(), in.end(), po[c]) - in.begin();
        TreeNode* temp = new TreeNode(po[c--]);
        
        temp -> right = solve(in,po, ind+1, b, c);
        temp -> left = solve(in, po, a, ind-1, c);
        return temp;
        
    }
    
    TreeNode* buildTree(vector<int>& in, vector<int>& po){
        int a = 0;
        int b = in.size()-1;
        int c = b;
        return solve(in,po,a,b,c);
    }
};